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
    wxapi.SetParam("r", ~static_cast<int>(Util::GetUtcMilli()));
    wxapi.SetParam("pass_ticket", pass_ticket);
    auto request = r_factory();
    request->SetUrl(wxapi.url);

    auto response = session.Post(*request, payload.dump());
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    UpdateSyncKey(response->Response());

    hdl.WxInit(response->Response());
}

std::string WxClient::GetHeadImage(const std::string &headimg_url) const
{
    return GetHeadImage(session, headimg_url);
}

std::string WxClient::GetHeadImage(const VrSession& session, const std::string &headimg_url) const
{
    auto request = r_factory();
    request->SetUrl(Wx.url + headimg_url);

    auto response = session.Get(*request);
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    return response->Response();
}

std::string WxClient::GetContactList() const
{
    return GetContactList(session);
}

std::string WxClient::GetContactList(const VrSession& session) const
{
    auto wxapi = WxContactList;
    wxapi.SetParam("pass_ticket", pass_ticket);
    wxapi.SetParam("r", static_cast<int>(Util::GetUtcMilli()));
    wxapi.SetParam("skey", skey);

    auto request = r_factory();
    request->SetUrl(wxapi.url);

    auto response = session.Get(*request);
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    return response->Response();
}

std::string WxClient::GetContactInfo(const std::vector<std::pair<std::string, std::string>>& pairs) const
{
    return GetContactInfo(session, pairs);
}

std::string WxClient::GetContactInfo(const VrSession& session, const std::vector<std::pair<std::string, std::string>>& pairs) const
{
    auto wxapi = WxContactInfo;
    wxapi.SetParam("pass_ticket", pass_ticket);
    wxapi.SetParam("r", static_cast<int>(Util::GetUtcMilli()));

    auto request = r_factory();
    request->SetUrl(wxapi.url);

    json payload;
    json base_request;
    base_request["Uin"] = wxuin;
    base_request["Sid"] = wxsid;
    base_request["Skey"] = skey;
    base_request["DeviceID"] = "e762880274648329";
    payload["BaseRequest"] = base_request;
    payload["Count"] = pairs.size();
    json::array_t list;
    for(auto i : pairs) {
        list.push_back({{"UserName", i.first}, {"EncryChatRoomId", i.second}});
    }
    payload["List"] = list;

    auto response = session.Post(*request, payload.dump());
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    return response->Response();
}

void WxClient::WxSync()
{
    WxSync(session);
}

void WxClient::WxSync(const VrSession& session)
{
    json payload;
    json base_request;
    base_request["Uin"] = wxuin;
    base_request["Sid"] = wxsid;
    base_request["Skey"] = skey;
    base_request["DeviceID"] = "e762880274648329";
    payload["BaseRequest"] = base_request;
    payload["SyncKey"] = json::parse(synckey_json);
    payload["rr"] = ~static_cast<int>(Util::GetUtcMilli());

    auto wxapi = WeChat_Http::WxSync;
    wxapi.SetParam("sid", wxsid);
    wxapi.SetParam("skey", skey);
    wxapi.SetParam("pass_ticket", pass_ticket);

    auto request = r_factory();
    request->SetUrl(wxapi.url);

    auto response = session.Post(*request, payload.dump());
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    auto text = response->Response();

    UpdateSyncKey(text);

    ControlOnSync(text);
}

void WxClient::WxSyncCheck()
{
    WxSyncCheck(session);
}

void WxClient::WxSyncCheck(const VrSession& session)
{
    auto wxapi = WeChat_Http::WxSyncCheck;
    wxapi.SetParam("r", Util::GetUtcMilli());
    wxapi.SetParam("skey", skey);
    wxapi.SetParam("sid", wxsid);
    wxapi.SetParam("synckey", synckey);

    auto request = r_factory();
    request->SetUrl(wxapi.url);

    auto response = session.Get(*request);
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    auto text = response->Response();
    auto colon_first = text.find_first_of(":"),
         colon_second = text.find_last_of(":");
    auto d_quote_first = text.find("\"", colon_first + 2),
         d_quote_second = text.find("\"", colon_second + 2);

    int retcode = std::atoi(text.substr(colon_first + 2, d_quote_first - colon_first - 2).data()),
        selector = std::atoi(text.substr(colon_second + 2, d_quote_second - colon_second - 2).data());

/*
 *    if(retcode != 0 && selector == 0) {
 *        WxSync();
 *    } else if(retcode == 0 && selector == 0) {
 *
 *    } else {
 *        WxSync();
 *    }
 */
    if(retcode != 0 || selector != 0) {
        WxSync();
    }

    throw std::runtime_error("wechat sync failed");
}

json& SendingPayload(json& payload, const std::string& content, const std::string& from, const std::string& to, int type)
{
    json msg;
    msg["Type"] = type;
    msg["Content"] = content;
    msg["FromUserName"] = from;
    msg["ToUserName"] = to;
    msg["LocalID"] = std::to_string(WeChat_Http::Util::GetUtcMilli()).append("0").append(std::to_string((std::rand() & 0x1ff) + 100));
    msg["ClientMsgId"] = msg["LocalId"].get<std::string>();

    payload["Msg"] = msg;
    return payload;
}

bool WxClient::SendText(const std::string& msg, const std::string& from, const std::string& to) const
{
    auto wxapi = WeChat_Http::WxGetImg;
    wxapi.SetParam("pass_ticket", pass_ticket);

    auto request = r_factory();
    request->SetUrl(wxapi.url);

    json payload;
    json base_request;
    base_request["Uin"] = wxuin;
    base_request["Sid"] = wxsid;
    base_request["Skey"] = skey;
    base_request["DeviceID"] = "e762880274648329";
    payload["BaseRequest"] = base_request;
    auto response = session.Post(*request, SendingPayload(payload, msg, from, to, 1).dump());
    if(response->Error()) throw std::runtime_error(response->Error().ErrorMessage());

    json ret_json = json::parse(response->Response());

    /*@TODO
     */

    return true;
}

std::string WxClient::DumpSyncKey(std::vector<std::map<std::string, int>> synckeys)
{
    std::string s;
    for (auto i : synckeys) {
        if(!s.empty()) s.append("|");
        s.append(std::to_string(i["Key"])).append("_").append(std::to_string(i["Val"]));
    }
    return s;
}

void WxClient::UpdateSyncKey(const std::string& res_text_in_json)
{
    auto res_json = json::parse(res_text_in_json);
    synckey = DumpSyncKey(res_json["SyncKey"]["List"]);
    synckey_json = res_json["SyncKey"].dump();
}
