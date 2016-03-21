#include "wxmodel.hpp"

#define JSON_GET(json, data) data = json[#data].get<decltype(data)>()

namespace WebWx {
    namespace Model {
        WxBaseResponse::WxBaseResponse() {}

        WxBaseResponse::WxBaseResponse(const json& j)
        {
            JSON_GET(j, Ret);
            JSON_GET(j, ErrMsg);
        }

        WxMember::WxMember() {}

        WxMember::WxMember(const json& j)
        {

        }

        WxMsg::WxMsg() {}

        WxMsg::WxMsg(const json& j)
        {

        }

        WxContact::WxContact() {}

        WxContact::WxContact(const json& j)
        {

        }

        WxInitResponse::WxInitResponse() {}

        WxInitResponse::WxInitResponse(const std::string& res_in_json)
        {

        }

        WxGetContactResponse::WxGetContactResponse() {}

        WxGetContactResponse::WxGetContactResponse(const std::string& res_in_json)
        {

        }

        WxBatchContactResponse::WxBatchContactResponse() {}

        WxBatchContactResponse::WxBatchContactResponse(const std::string& res_in_json)
        {

        }

        WxSyncResponse::WxSyncResponse() {}

        WxSyncResponse::WxSyncResponse(const std::string& res_in_json)
        {

        }

        WxSendResponse::WxSendResponse() {}

        WxSendResponse::WxSendResponse(const std::string& res_in_json)
        {

        }
    }
}
