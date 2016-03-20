#pragma once

#ifndef WECHAT_HPP_PBKITHXS
#define WECHAT_HPP_PBKITHXS

#include <string>
#include <ctime>

#include "vrhttp.hpp"

namespace WeChat_Http {

    using VrSession = WeChat_Http::VirtualHttpSession;
    using VrReply = WeChat_Http::VirtualHttpReply;
    using VrRequest = WeChat_Http::VirtualHttpRequest;
    using VrReqFactory = decltype(WeChat_Http::NewVirtualHttpRequest_NULLPTR);

    static const std::string User_Agent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.75 Safari/537.36";

    static const std::string Referer = "https://wx.qq.com/?lang=en_US";

    class WxWebApi {
    public:
        explicit WxWebApi(std::string url)
            : url(url) {}
        std::string url;

        void SetParam(std::string key, std::string value) {
            auto x = url.find_first_of(key + "=");
            if (x == std::string::npos) return;
            if (url.substr(x += key.size() + 1, 4) == "{##}") {
                url.replace(x, 4,value);
            }
        }

        void SetParam(std::string key, std::int64_t value) {
            SetParam(key, std::to_string(value));
        }
    };

    extern const WxWebApi Wx, WxQRUUid, WxQR, WxLoginCheck, WxGetImg,
           WxInit, WxIcon, WxHeadImg, WxContact, WxSyncCheck, WxSync, WxSendImg;

    class WxCtl {
    protected:
        WxCtl() {}
        virtual ~WxCtl() {};
    public:
        virtual void QRload(std::string qr_url) = 0;

        virtual void WxInit(const std::string& json_string) = 0;

        virtual void ContactsRefresh() = 0;
    };

    class WxClient {
    private:
        VrSession& session;
        VrReqFactory& r_factory;

        WxCtl& ctl;

    public:
        WxClient(VrSession& session, VrReqFactory& reqfactory, WxCtl& ctl)
            : session(session) , r_factory(reqfactory), ctl(ctl) {}

        void Login();

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
        std::string qr_uuid;

        std::string wxsid;
        std::string wxuin;
        std::string pass_ticket;
        std::string skey;

        void WxInit();

        std::string GetQRCode();

        std::string LoginCheckLoop();

        void GetSidAndUid(const std::string& url);

    };
}

#endif /* end of include guard: WECHAT_HPP_PBKITHXS */
