#pragma once

#ifndef WECHAT_HPP_PBKITHXS
#define WECHAT_HPP_PBKITHXS

#include <string>
#include <ctime>
#include <vector>

#include "vrhttp.hpp"
#include "wxapi.hpp"
#include "wxhandler.hpp"

#include "models/wx_baserequest.hpp"

namespace WebWx {

    using VrSession = Http::VirtualHttpSession;
    using VrReply = Http::VirtualHttpReply;
    using VrRequest = Http::VirtualHttpRequest;
    using VrReqFactory = decltype(Http::NewVirtualHttpRequest_NULLPTR);

    static const std::string User_Agent = "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.75 Safari/537.36";

    static const std::string Referer = "https://wx.qq.com/?lang=en_US";

    using WxHandler = WebWx::WxHandler;

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
        void GetContact() const;
        void BatchGetContact(const std::vector<std::pair<std::string, std::string>>& username_encrychatroomids) const;
        void WxSyncCheck();
        bool SendText(const std::string& msg, const std::string& from, const std::string& to) const;
        bool SendImage(const std::string& img_uri, const std::string& from, const std::string& to) const;
        bool SendFile(const std::string& file_uri, const std::string& from, const std::string& to) const;

        // set of functions using different http session
        std::string GetHeadImage(const VrSession& session, const std::string& headimg_url) const;
        void GetContact(const VrSession& session) const;
        void BatchGetContact(const VrSession& session, const std::vector<std::pair<std::string, std::string>>& username_encrychatroomids) const;
        void WxSyncCheck(const VrSession& session);
        bool SendText(const VrSession& session, const std::string& msg, const std::string& from, const std::string& to) const;
        bool SendImage(const VrSession& session, const std::string& img_uri, const std::string& from, const std::string& to) const;
        bool SendFile(const VrSession& session, const std::string& file_uri, const std::string& from, const std::string& to) const;

    private:
        std::string qr_uuid;

        WebWx::Model::WxBaseRequest base_request;

        std::string& wxsid = base_request.Sid;
        std::string& wxuin = base_request.Uin;
        std::string& skey = base_request.Skey;

        std::string pass_ticket;

        std::string synckey;
        std::string synckey_json;

    private:
        void WxInit();
        std::string GetQRCode();
        std::string LoginCheckLoop();

        void GetSidAndUid(const std::string& url);

        void WxSync();
        void WxSync(const VrSession& session);

        void UpdateSyncKey(const std::string& res_text_in_json);

        void ControlOnSync(const Model::WxSyncResponse &res);

        static std::string DumpSyncKey(std::vector<std::map<std::string, int>> synckeys);

        static void SetRequestHead();

    };
}

#endif /* end of include guard: WECHAT_HPP_PBKITHXS */
