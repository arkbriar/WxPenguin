#include "json/json.hpp"
#include "util.hpp"
#include "wechat.hpp"

using json = nlohmann::json;

using WxClient = WeChat_Http::WxClient;

// extern function from msg.cc
json& SendingPayload(json& payload, const std::string& content, const std::string& from, const std::string& to, int type);

bool WxClient::SendImage(const VrSession& session, const std::string& img_uri, const std::string& from, const std::string& to) const
{
    return true;
}

bool WxClient::SendImage(const std::string& img_uri, const std::string& from, const std::string& to) const
{

    return SendImage(session, img_uri, from, to);
}

bool WxClient::SendFile(const VrSession& session, const std::string& file_uri, const std::string& from, const std::string& to) const
{
    return true;
}

bool WxClient::SendFile(const std::string& file_uri, const std::string& from, const std::string& to) const
{

    return SendFile(session, file_uri, from, to);
}
