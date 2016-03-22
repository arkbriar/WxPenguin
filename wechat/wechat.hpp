#pragma once

#ifndef WECHAT_HPP_PBKITHXS
#define WECHAT_HPP_PBKITHXS

#include <string>
#include <ctime>
#include <vector>

#include "vrhttp.hpp"
#include "wxapi.hpp"

namespace WeChat_Http {

    using VrSession = WeChat_Http::VirtualHttpSession;
    using VrReply = WeChat_Http::VirtualHttpReply;
    using VrRequest = WeChat_Http::VirtualHttpRequest;
    using VrReqFactory = decltype(WeChat_Http::NewVirtualHttpRequest_NULLPTR);

    static const std::string User_Agent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.75 Safari/537.36";

    static const std::string Referer = "https://wx.qq.com/?lang=en_US";

    class WxHandler {
    protected:
        WxHandler() {}
        virtual ~WxHandler() {};
    public:
        /* on login */
        virtual void QRload(const std::string& qr_url) = 0;
        virtual void AvatarLoad(const std::string& avatar) = 0;

        /* after login */
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

        WxHandler& hdl;

    public:
        WxClient(VrSession& session, VrReqFactory& reqfactory, WxHandler& hdl)
            : session(session), r_factory(reqfactory), hdl(hdl) {}

        ~WxClient() {}

        void Login();
        void Logout();

        // set of functions using http session of client
        std::string GetHeadImage(const std::string& headimg_url) const;
        std::string GetContactList() const;
        std::string GetContactInfo(const std::vector<std::pair<std::string, std::string>>& username_encrychatroomids) const;
        void WxSyncCheck();
        bool SendText(const std::string& msg, const std::string& from, const std::string& to) const;
        bool SendImage(const std::string& img_uri, const std::string& from, const std::string& to) const;
        bool SendFile(const std::string& file_uri, const std::string& from, const std::string& to) const;

        // set of functions using different http session
        std::string GetHeadImage(const VrSession& session, const std::string& headimg_url) const;
        std::string GetContactList(const VrSession& session) const;
        std::string GetContactInfo(const VrSession& session, const std::vector<std::pair<std::string, std::string>>& username_encrychatroomids) const;
        void WxSyncCheck(const VrSession& session);
        bool SendText(const VrSession& session, const std::string& msg, const std::string& from, const std::string& to) const;
        bool SendImage(const VrSession& session, const std::string& img_uri, const std::string& from, const std::string& to) const;
        bool SendFile(const VrSession& session, const std::string& file_uri, const std::string& from, const std::string& to) const;

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
        void WxSync(const VrSession& session);

        void UpdateSyncKey(const std::string& res_text_in_json);

        void ControlOnSync(const std::string& res_text_in_json);

        static std::string DumpSyncKey(std::vector<std::map<std::string, int>> synckeys);

        static void SetRequestHead();

    };
}

#endif /* end of include guard: WECHAT_HPP_PBKITHXS */
