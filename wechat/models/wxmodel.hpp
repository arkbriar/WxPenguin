#pragma once

#ifndef WXMODEL_HPP_X6UWAUQA
#define WXMODEL_HPP_X6UWAUQA

#include <vector>
#include <string>
#include <cstdint>

#include "wx_msg.hpp"
#include "wx_contact.hpp"
#include "wx_synckey.hpp"
#include "wx_baseresponse.hpp"

#include "msgtype.hpp"
#include "../json/json.hpp"

namespace WebWx {
    namespace Model {

        using json = nlohmann::json;

        class WxInitResponse;

        class WxGetContactResponse;
        class WxBatchContactResponse;

        class WxSyncResponse;

        class WxSendResponse;

        class WxInitResponse {
        public:
            class WxMPSubscribeMsg {
            public:
                //@no impl
                WxMPSubscribeMsg() {}
                WxMPSubscribeMsg(const json&) {}
            };

            class WxUser {
            public:
                WxUser();
                WxUser(const json&);

                int AppAcountFlag;
                int ContactFlag;
                int HeadImgFlag;
                std::string HeadImgUrl;
                int HideInputBarFlag;
                std::string NickName;
                std::string PYInitial;
                std::string PYQuanPin;
                std::string RemarkName;
                std::string RemarkPYInitial;
                std::string RemarkPYQuanPin;
                int Sex;
                std::string Signature;
                int SnsFlag;
                int StarFriend;
                int Uin;
                std::string UserName;
                int VerifyFlag;
                int WebWxPluginSwitch;
            };

            WxInitResponse();
            WxInitResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::string ChatSet;
            int ClickReportInterval;
            int ClientVersion;
            int Count;
            std::vector<WxContact> ContactList;
            int GrayScale;
            int InviteStartCount;
            int MPSubscribeMsgCount;
            std::vector<WxMPSubscribeMsg> MPSubscribeMsgList;
            std::string SKey;
            WxSyncKey SyncKey;
            int SystemTime;
            WxUser User;

        protected:
            WxInitResponse(const json&);
        };

        class WxGetContactResponse {
        public:
            WxGetContactResponse();
            WxGetContactResponse(const std::string&);

            WxBaseResponse BaseResponse;
            int MemberCount;
            std::vector<WxContact> MemberList;
            int Seq;

        protected:
            WxGetContactResponse(const json&);
        };

        class WxBatchContactResponse {
        public:
            WxBatchContactResponse();
            WxBatchContactResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::vector<WxContact> ContactList;
            int Count;

        protected:
            WxBatchContactResponse(const json&);
        };

        class WxSyncResponse {
        public:
            WxSyncResponse();
            WxSyncResponse(const std::string&);

            WxBaseResponse BaseResponse;
            int AddMsgCount;
            std::vector<WxMsg> AddMsgList;
            int ModContactCount;
            std::vector<WxContact> ModContactList;
            WxSyncKey SyncKey;

        protected:
            WxSyncResponse(const json&);
        };

        class WxSendResponse {
        public:
            WxSendResponse();
            WxSendResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::string MsgID;
            std::string LocalID;

        protected:
            WxSendResponse(const json&);
        };
    }
}


#endif /* end of include guard: WXMODEL_HPP_X6UWAUQA */
