#pragma once

#ifndef WXMODEL_HPP_X6UWAUQA
#define WXMODEL_HPP_X6UWAUQA

#include <vector>
#include <string>
#include <map>

#include "msgtype.hpp"
#include "../json/json.hpp"

namespace WebWx {
    namespace Model {

        using json = nlohmann::json;

        struct WxBaseResponse {
            WxBaseResponse();
            WxBaseResponse(const json&);

            int Ret;
            std::string ErrMsg;
        };

        struct WxSyncKey {
            //@no impl
        };

        struct WxMsg {
            WxMsg();
            WxMsg(const json&);
        };

        struct WxMember {
            WxMember();
            WxMember(const json&);

            int Uin;
            std::string UserName;
            std::string NickName;
            int AttrStatus;
            std::string PYInitial;
            std::string PYQuanPin;
            std::string RemarkPYInitial;
            std::string RemarkPYQuanPin;
            int MemberStatus;
            std::string DisplayName;
            std::string KeyWord;
        };

        struct WxContact {
            WxContact();
            WxContact(const json&);
            bool IsGroup() const {return MemberCount != 0;}

            int Uin;
            std::string UserName;
            std::string NickName;
            std::string HeadImgUrl;
            int ContactFlag;
            int MemberCount;
            std::vector<WxMember> MemberList;
            std::string RemarkName;
            int Sex;
            std::string Signature;
            int VerifyFlag;
            std::string PYInitial;
            std::string PYQuanPin;
            std::string RemarkPYInitial;
            std::string RemarkPYQuanPin;
            int StarFriend;
            int AppAcountFlag;
            int Statues;
            int AttrStatus;
            std::string Province;
            std::string City;
            std::string Alias;
            int SnsFlag;
            int UniFriend;
            std::string DisplayName;
            int ChatRoomId;
            std::string KeyWord;
            std::string EncryChatRoomId;
        };


        struct WxMPSubscribeMsg {
            //@no impl
        };

        struct WxInitResponse {
            WxInitResponse();
            WxInitResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::string ChatSet;
            int ClickReportInterval;
            int ClientVersion;
            std::vector<WxContact> ContactList;
            int GrayScale;
            int InviteStartCount;
            std::vector<WxMPSubscribeMsg> MPSubscribeMsgList;
            std::string SKey;
            WxSyncKey SyncKey;
            int SystemTime;
            WxContact User;
        };

        struct WxGetContactResponse {
            WxGetContactResponse();
            WxGetContactResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::vector<WxContact> MemberList;
            int Seq;
        };

        struct WxBatchContactResponse {
            WxBatchContactResponse();
            WxBatchContactResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::vector<WxContact> ContactList;
        };

        struct WxSyncResponse {
            WxSyncResponse();
            WxSyncResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::vector<WxMsg> AddMsgList;
            std::vector<WxContact> ModContactList;
            WxSyncKey SyncKey;
        };

        struct WxSendResponse {
            WxSendResponse();
            WxSendResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::string MsgID;
            std::string LocalID;
        };
    }
}


#endif /* end of include guard: WXMODEL_HPP_X6UWAUQA */
