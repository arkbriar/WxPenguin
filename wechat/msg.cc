#include "json/json.hpp"
#include "util.hpp"
#include "wechat.hpp"

using json = nlohmann::json;

using WxClient = WeChat_Http::WxClient;

void WxClient::WxInit()
{
    json payload;
    json base_request;
    base_request["Uin"] = wxuin;
    base_request["Sid"] = wxsid;
    base_request["Skey"] = skey;
    base_request["DeviceID"] = "e762880274648329";
    payload["BaseRequest"] = base_request;

    auto wxapi = WeChat_Http::WxInit;
    wxapi.SetParam("pass_ticket", Util::UrlEncode(pass_ticket));
    auto request = r_factory();
    request->SetUrl(wxapi.url);

    auto response = session.Post(*request, payload.dump());
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    ctl.WxInit(response->Response());
}

std::string WxClient::GetIcon(std::string username)
{

    throw std::runtime_error("can not get icon");
}

std::string WxClient::GetHeadImage(std::string username)
{

    throw std::runtime_error("can not get headimg");
}

void WxClient::GetContact()
{

}

void WxClient::WxSync()
{

}

std::string WxClient::WxSyncCheck()
{

    throw std::runtime_error("wechat sync failed");
}
