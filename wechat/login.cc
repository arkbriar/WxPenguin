#include <thread>
#include <chrono>
#include <regex>

#include "util.hpp"
#include "wxclient.hpp"

using WxClient = WebWx::WxClient;

std::string WxClient::GetQRCode()
{
    // get qrlogin uuid
    auto wxapi = WxQRUUid;
    wxapi.SetParam("_", Util::GetUtcMilli());

    auto request = r_factory();
    request->SetUrl(wxapi.url);

    auto response = session.Get(*request);
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    auto text = response->Response();
    Util::RemoveSpaces(text);

    auto ress = Util::split(text, ';');

    int qrlogin_code = Util::GetIntAfterTheLastEqual(ress[0]);
    if(200 == qrlogin_code) {
        std::string& uuid_s = ress[1];
        auto first = uuid_s.find_first_of("\""), last = uuid_s.find_last_of("\"");
        qr_uuid = uuid_s.substr(first + 1, last - first - 1);
    } else {
        throw std::runtime_error("invalid qrlogin code");
    }

    // get qr code's url
    wxapi = WxQR;
    wxapi.url.append(qr_uuid);

    return wxapi.url;
}

std::string WxClient::LoginCheckLoop() {
    bool isScan = false;
    bool isConfirm = false;
    while (!isScan || !isConfirm) {
        auto wxapi = WxLoginCheck;
        if(isScan) wxapi = WxLoginCheckAfterScan;
        wxapi.SetParam("uuid", qr_uuid);
        wxapi.SetParam("r", ~static_cast<int>(Util::GetUtcMilli()));
        wxapi.SetParam("_", Util::GetUtcMilli());

        auto request = r_factory();
        request->SetUrl(wxapi.url);

        auto response = session.Get(*request);
        if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

        auto text = response->Response();
        Util::RemoveSpaces(text);

        auto ress = Util::split(text, ';');
        switch(Util::GetIntAfterTheLastEqual(ress[0])) {
            case 200:
                {
                    std::string& redirect_uri = ress[1];
                    auto first = redirect_uri.find_first_of("\""), last = redirect_uri.find_last_of("\"");
                    auto uri = redirect_uri.substr(first + 1, last - first - 1);

                    uri.append("&fun=new&version=v2&lang=en_US");
                    return uri;
                }
                isScan = isConfirm = true;
                break;
            case 201:
                {
                    std::string& userAvatar = ress[1];
                    auto comma = userAvatar.find_first_of(",");
                    // load avatar on scan
                    if(std::string::npos != comma)
                        hdl.AvatarLoad(userAvatar.substr(comma + 1, userAvatar.size() - comma - 1));
                }
                isScan = true;
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            case 408:
                break;
            case 400:
            case 500:
            case 0:
            default:
                isScan = isConfirm = false;
                hdl.QRload(GetQRCode());
                break;
        }
    }
    throw std::runtime_error(std::string("should not reach here: ").append(__PRETTY_FUNCTION__));
}

void WxClient::GetSidAndUid(const std::string& url)
{
    auto request = r_factory();
    request->SetUrl(url);

    auto response = session.Get(*request);
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    auto text = response->Response();

    std::smatch match;
    static const std::regex ret_p("(<ret>)(.*)(</ret>)");
    static const std::regex message_p("(<message>(.*)</message>)");

    if(std::regex_match(text, match, ret_p)) {
        int ret = std::atoi(match[2].str().c_str());
        if(ret != 0) {
            if(std::regex_match(text, match, message_p)) {
                throw std::runtime_error(std::string(__PRETTY_FUNCTION__).append(": ").append(match[2]));
            } else {
                throw std::runtime_error(std::string(__PRETTY_FUNCTION__).append(": can not find error message"));
            }
        }
    } else {
        throw std::runtime_error(std::string(__PRETTY_FUNCTION__).append(": can not find ret code"));
    }

    // sid and uid in cookie, skey and pass_ticket in text
    static const std::regex skey_p("(<skey>)(.*)(</skey>)");
    static const std::regex pass_ticket_p("(<pass_ticket>)(.*)(</pass_ticket>)");

    if(std::regex_search(text, match, skey_p)) {
        skey = match[2];
    } else {
        throw std::runtime_error("cannot find skey in response");
    }

    if(std::regex_search(text, match, pass_ticket_p)) {
        pass_ticket = match[2];
    } else {
        throw std::runtime_error("cannot find pass_ticket in response");
    }

    wxsid = session.GetCookieValue("wxsid");
    wxuin = session.GetCookieValue("wxuin");
    if(wxsid.empty() || wxuin.empty()) {
        throw std::runtime_error("can not find wxsid or wxuin in cooike");
    }
}

void WxClient::Login()
{
    hdl.QRload(GetQRCode());
    GetSidAndUid(LoginCheckLoop());
    WxInit();
}

void WxClient::Logout()
{

}

