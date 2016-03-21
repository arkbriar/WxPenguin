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

    namespace Util {
        std::string UrlEncode(const std::string& value);
    }

    class WxWebApi {
    public:
        explicit WxWebApi(std::string url)
            : url(url) {}
        std::string url;

        void SetParam(std::string key, std::string value) {
            auto x = url.find_first_of(key + "=");
            if (x == std::string::npos) return;
            if (url.substr(x += key.size() + 1, 4) == "{##}") {
                url.replace(x, 4, Util::UrlEncode(value));
            }
        }

        void SetParam(std::string key, std::int64_t value) {
            SetParam(key, std::to_string(value));
        }
    };

    extern const WxWebApi Wx, WxQRUUid, WxQR, WxLoginCheck, WxGetImg, WxLoginCheckAfterScan,
           WxInit, WxIcon, WxHeadImg, WxContactList, WxContactInfo, WxSyncCheck, WxSync, WxSendImg;

    class WxCtl {
    protected:
        WxCtl() {}
        virtual ~WxCtl() {};
    public:
        virtual void QRload(const std::string& qr_url) = 0;
        virtual void AvatarLoad(const std::string& avatar) = 0;
        virtual void WxInit(const std::string& json_string) = 0;
        virtual void ContactsRefresh() = 0;
        virtual void ChatRefresh(const std::string& username, const std::string& context) = 0;
        virtual void Voice(const std::string& voice_url) = 0;

        virtual void Image(const std::string& iamge_url) = 0;
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

        std::string GetHeadImage(const std::string& headimg_url) const;

        std::string GetContactList() const;

        std::string GetContactInfo(const std::vector<std::pair<std::string, std::string>>& username_encrychatroomids) const;

        void WxSyncCheck();

        void SendMsg(std::string msg, std::string from, std::string to, int type) const;

        void SendImage(std::string img_uri) const;

        void SendFile(std::string file_uri) const;

    private:
        std::string qr_uuid;

        std::string wxsid;
        std::string wxuin;
        std::string pass_ticket;
        std::string skey;

        std::string synckey;
        std::string synckey_json;

        void WxInit();
        std::string GetQRCode();
        std::string LoginCheckLoop();

        void GetSidAndUid(const std::string& url);

        void WxSync();

        static std::string DumpSyncKey(std::vector<std::map<std::string, int>> synckeys);

        void UpdateSyncKey(const std::string& res_text_in_json);
        void ControlOnSync(const std::string& res_text_in_json);
    };
}

#endif /* end of include guard: WECHAT_HPP_PBKITHXS */
