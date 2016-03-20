#pragma once

#ifndef WECHAT_HPP_PBKITHXS
#define WECHAT_HPP_PBKITHXS

#include <string>

#include "vrhttp.hpp"

namespace WeChat_Http {

    using VrSession = WeChat_Http::VirtualHttpSession;
    using VrReply = WeChat_Http::VirtualHttpReply;
    using VrRequest = WeChat_Http::VirtualHttpRequest;
    using VrReqFactory = decltype(WeChat_Http::NewVirtualHttpRequest_NULLPTR);

    static const std::string User_Agent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.75 Safari/537.36";

    static const std::string Referer = "https://wx.qq.com";

    class WxWebApi {
    public:
        explicit WxWebApi(std::string url)
            : url(url) {}
        std::string url;
    };

    extern WxWebApi Wx, WxQRUUid, WxQR, WxLoginCheck,
           WxInit, WxIcon, WxHeadImg, WxContact, WxSyncCheck, WxSync, WxSendImg;

    class WxClient {
    private:
        VrSession& session;
        VrReqFactory& reqfactory;

    public:
        WxClient(VrSession& session, VrReqFactory& reqfactory)
            : session(session) , reqfactory(reqfactory){}

        std::string GetQRCode();

        void LoginCheck();

        void GetSidAndUid();

        void Logout();

        std::string GetIcon(std::string username);

        std::string GetHeadImage(std::string username);

        void GetContact();

        std::string WxSyncCheck();

        void WxSync();

        void SendMsg(std::string msg, std::string from, std::string to, int type);

        void SendImage(std::string img_uri);

        void SendFile(std::string file_uri);

    private:

        void WxInit();
    };

}

#endif /* end of include guard: WECHAT_HPP_PBKITHXS */
