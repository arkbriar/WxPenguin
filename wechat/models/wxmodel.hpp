#pragma once

#ifndef WXMODEL_HPP_X6UWAUQA
#define WXMODEL_HPP_X6UWAUQA

#include <vector>
#include <string>
#include <map>
#include <cstdint>

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
            //@no impl/
            WxSyncKey() {}
            WxSyncKey(const json&) {}
        };

        struct WxRecommendInfo {
            WxRecommendInfo();
            WxRecommendInfo(const json&);

            std::string UserName;
            std::string NickName;
            int QQNum;
            std::string Province;
            std::string City;
            std::string Content;
            std::string Signature;
            std::string Alias;
            int Scene;
            int VerifyFlag;
            int AttrStatus;
            int Sex;
            std::string Ticket;
            int OpCode;
        };

        struct WxAppInfo {
            WxAppInfo();
            WxAppInfo(const json&);

            std::string AppID;
            int Type;
        };

        struct WxMsg {
            WxMsg();
            WxMsg(const json&);

            std::string MsgId;
            std::string FromUserName;
            std::string ToUserName;
            int MsgType;
            std::string Content;
            int Status;
            int ImgStatus;
            int CreateTime;
            int VoiceLength;
            int PlayLength;
            std::string FileName;
            std::string FileSize;
            std::string MediaId;
            std::string Url;
            int AppMsgType;
            int StatusNotifyCode;
            int StatusNotifyUserName;
            WxRecommendInfo RecommendInfo;
            int ForwardFlag;
            WxAppInfo AppInfo;
            int HasProductId;
            std::string Ticket;
            int ImgHeight;
            int ImgWidth;
            int SubMsgType;
            std::uint64_t NewMsgId;
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
            WxMPSubscribeMsg() {}
            WxMPSubscribeMsg(const json&) {}
        };

        struct WxUser {
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

        struct WxInitResponse {
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

        struct WxGetContactResponse {
            WxGetContactResponse();
            WxGetContactResponse(const std::string&);

            WxBaseResponse BaseResponse;
            int MemberCount;
            std::vector<WxContact> MemberList;
            int Seq;

        protected:
            WxGetContactResponse(const json&);
        };

        struct WxBatchContactResponse {
            WxBatchContactResponse();
            WxBatchContactResponse(const std::string&);

            WxBaseResponse BaseResponse;
            std::vector<WxContact> ContactList;
            int Count;

        protected:
            WxBatchContactResponse(const json&);
        };

        struct WxSyncResponse {
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

        struct WxSendResponse {
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
