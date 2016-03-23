#include "wxmodel.hpp"

#define JSON_GET(_json, _data) _data = _json[#_data].get<decltype(_data)>()

#define JSON_GET_LIST(_json, _data_list) { \
    for (auto i : _json[#_data_list].get<std::vector<json>>()) { \
        _data_list.push_back(i); \
    } \
}

namespace WebWx {
    namespace Model {

        using WxRecommendInfo = WxMsg::WxRecommendInfo;
        using WxAppInfo = WxMsg::WxAppInfo;
        using WxMember = WxContact::WxMember;
        using WxUser = WxInitResponse::WxUser;

        WxBaseResponse::WxBaseResponse() {}

        WxBaseResponse::WxBaseResponse(const json& j)
        {
            JSON_GET(j, Ret);
            JSON_GET(j, ErrMsg);
        }

        WxRecommendInfo::WxRecommendInfo() {}

        WxRecommendInfo::WxRecommendInfo(const json& j)
        {
            JSON_GET(j, UserName);
            JSON_GET(j, NickName);
            JSON_GET(j, QQNum);
            JSON_GET(j, Province);
            JSON_GET(j, City);
            JSON_GET(j, Content);
            JSON_GET(j, Signature);
            JSON_GET(j, Alias);
            JSON_GET(j, Scene);
            JSON_GET(j, Sex);
            JSON_GET(j, Ticket);
            try {
                JSON_GET(j, AttrStatus);
                JSON_GET(j, VerifyFlag);
                JSON_GET(j, OpCode);
            } catch (std::domain_error e) {

            }
        }

        WxAppInfo::WxAppInfo() {}
        WxAppInfo::WxAppInfo(const json& j)
        {
            JSON_GET(j, AppID);
            JSON_GET(j, Type);
        }

        WxMsg::WxMsg() {}

        WxMsg::WxMsg(const json& j)
            : RecommendInfo(j["RecommendInfo"]), AppInfo(j["AppInfo"])
        {
            JSON_GET(j, MsgId);
            JSON_GET(j, FromUserName);
            JSON_GET(j, ToUserName);
            JSON_GET(j, MsgType);
            JSON_GET(j, Content);
            JSON_GET(j, Status);
            JSON_GET(j, ImgStatus);
            JSON_GET(j, CreateTime);
            JSON_GET(j, VoiceLength);
            JSON_GET(j, PlayLength);
            JSON_GET(j, FileName);
            JSON_GET(j, FileSize);
            JSON_GET(j, MediaId);
            JSON_GET(j, Url);
            JSON_GET(j, AppMsgType);
            JSON_GET(j, StatusNotifyCode);
            JSON_GET(j, StatusNotifyUserName);
            JSON_GET(j, ForwardFlag);
            JSON_GET(j, HasProductId);
            JSON_GET(j, Ticket);
            JSON_GET(j, ImgHeight);
            JSON_GET(j, ImgWidth);
            JSON_GET(j, SubMsgType);
            JSON_GET(j, NewMsgId);
        }

        WxMember::WxMember() {}

        WxMember::WxMember(const json& j)
        {
            JSON_GET(j, Uin);
            JSON_GET(j, UserName);
            JSON_GET(j, NickName);
            JSON_GET(j, AttrStatus);
            JSON_GET(j, PYInitial);
            JSON_GET(j, PYQuanPin);
            JSON_GET(j, MemberStatus);
            JSON_GET(j, DisplayName);
            JSON_GET(j, KeyWord);

            try {
                JSON_GET(j, RemarkPYInitial);
                JSON_GET(j, RemarkPYQuanPin);
            } catch (std::domain_error e) {

            }
        }

        WxContact::WxContact() {}

        WxContact::WxContact(const json& j)
        {
            JSON_GET(j, Uin);
            JSON_GET(j, UserName);
            JSON_GET(j, NickName);
            JSON_GET(j, HeadImgUrl);
            JSON_GET(j, ContactFlag);
            JSON_GET(j, MemberCount);
            JSON_GET_LIST(j, MemberList);
            JSON_GET(j, RemarkName);
            JSON_GET(j, Sex);
            JSON_GET(j, Signature);
            JSON_GET(j, VerifyFlag);
            JSON_GET(j, PYInitial);
            JSON_GET(j, PYQuanPin);
            JSON_GET(j, Statues);
            JSON_GET(j, AttrStatus);
            JSON_GET(j, Province);
            JSON_GET(j, City);
            JSON_GET(j, Alias);
            JSON_GET(j, UniFriend);
            JSON_GET(j, DisplayName);
            JSON_GET(j, ChatRoomId);
            JSON_GET(j, KeyWord);
            JSON_GET(j, EncryChatRoomId);

            try {
                JSON_GET(j, RemarkPYInitial);
                JSON_GET(j, RemarkPYQuanPin);
                JSON_GET(j, StarFriend);
                JSON_GET(j, SnsFlag);
                JSON_GET(j, AppAcountFlag);
            } catch (std::domain_error e) {

            }
        }

        WxUser::WxUser() {}

        WxUser::WxUser(const json& j)
        {
            JSON_GET(j, AppAcountFlag);
            JSON_GET(j, ContactFlag);
            JSON_GET(j, HeadImgFlag);
            JSON_GET(j, HeadImgUrl);
            JSON_GET(j, NickName);
            JSON_GET(j, PYInitial);
            JSON_GET(j, PYQuanPin);
            JSON_GET(j, RemarkName);
            JSON_GET(j, Sex);
            JSON_GET(j, Signature);
            JSON_GET(j, StarFriend);
            JSON_GET(j, Uin);
            JSON_GET(j, UserName);

            try {
                JSON_GET(j, HideInputBarFlag);
                JSON_GET(j, SnsFlag);
                JSON_GET(j, VerifyFlag);
                JSON_GET(j, WebWxPluginSwitch);
                JSON_GET(j, RemarkPYInitial);
                JSON_GET(j, RemarkPYQuanPin);
            } catch (std::domain_error e) {

            }
        }

        WxInitResponse::WxInitResponse() {}

        WxInitResponse::WxInitResponse(const std::string& res_in_json)
            : WxInitResponse(json::parse(res_in_json)) {}

        WxInitResponse::WxInitResponse(const json& j)
            : BaseResponse(j["BaseResponse"]), SyncKey(j["SyncKey"]), User(j["User"])
        {
            JSON_GET(j, ChatSet);
            JSON_GET(j, ClientVersion);
            JSON_GET(j, Count);
            JSON_GET_LIST(j, ContactList);
            JSON_GET(j, InviteStartCount);
            JSON_GET(j, SKey);
            JSON_GET(j, SystemTime);

            try {
                JSON_GET(j, ClickReportInterval);
                JSON_GET(j, GrayScale);
                JSON_GET(j, MPSubscribeMsgCount);
                JSON_GET_LIST(j, MPSubscribeMsgList);
            } catch (std::domain_error e) {

            }
        }

        WxGetContactResponse::WxGetContactResponse() {}

        WxGetContactResponse::WxGetContactResponse(const std::string& res_in_json)
            : WxGetContactResponse(json::parse(res_in_json)) {}

        WxGetContactResponse::WxGetContactResponse(const json& j)
            : BaseResponse(j["BaseResponse"])
        {
            JSON_GET(j, MemberCount);
            JSON_GET_LIST(j, MemberList);
            JSON_GET(j, Seq);
        }

        WxBatchContactResponse::WxBatchContactResponse() {}

        WxBatchContactResponse::WxBatchContactResponse(const std::string& res_in_json)
            : WxBatchContactResponse(json::parse(res_in_json)) {}

        WxBatchContactResponse::WxBatchContactResponse(const json& j)
            : BaseResponse(j["BaseResponse"])
        {
            JSON_GET_LIST(j, ContactList);
            JSON_GET(j, Count);
        }

        WxSyncResponse::WxSyncResponse() {}

        WxSyncResponse::WxSyncResponse(const std::string& res_in_json)
            : WxSyncResponse(json::parse(res_in_json)) {}

        WxSyncResponse::WxSyncResponse(const json& j)
            : BaseResponse(j["BaseResponse"]), SyncKey(j["SyncKey"])
        {
            JSON_GET(j, AddMsgCount);
            JSON_GET_LIST(j, AddMsgList);
            JSON_GET(j, ModContactCount);
            JSON_GET_LIST(j, ModContactList);
        }

        WxSendResponse::WxSendResponse() {}

        WxSendResponse::WxSendResponse(const std::string& res_in_json)
            : WxSendResponse(json::parse(res_in_json)) {}

        WxSendResponse::WxSendResponse(const json& j)
            : BaseResponse(j["BaseResponse"])
        {
            try {
                JSON_GET(j, MsgID);
                JSON_GET(j, LocalID);
            } catch (std::domain_error e) {

            }
        }
    }
}
