#pragma once

#ifndef WX_MSG_HPP_ZFY2D0BN
#define WX_MSG_HPP_ZFY2D0BN

#include <string>

#include "../json/json.hpp"

namespace WebWx {
    namespace Model {

        class WxMsg {
        public:
            class WxRecommendInfo {
            public:
                WxRecommendInfo();
                WxRecommendInfo(const nlohmann::json&);

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

            class WxAppInfo {
            public:
                WxAppInfo();
                WxAppInfo(const nlohmann::json&);

                std::string AppID;
                int Type;
            };

            WxMsg();
            WxMsg(const nlohmann::json&);

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

    }
}


#endif /* end of include guard: WX_MSG_HPP_ZFY2D0BN */
