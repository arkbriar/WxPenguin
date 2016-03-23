#pragma once

#ifndef WXAPI_HPP_QAWQCV7K
#define WXAPI_HPP_QAWQCV7K

#include <string>

namespace WebWx {

    namespace Util {
        std::string UrlEncode(const std::string& value);
    }

    class WxWebAPI {
    public:
        explicit WxWebAPI(std::string url)
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

    extern const WxWebAPI
        Wx,
        WxQRUUid,
        WxQR,
        WxLoginCheck,
        WxGetImg,
        WxLoginCheckAfterScan,
        WxInit,
        WxIcon,
        WxHeadImg,
        WxContactList,
        WxContactInfo,
        WxSyncCheck,
        WxSync,
        WxSendImg;

    /*
     *extern const WxWebAPI
     *  API_jsLogin,
     *  API_login,
     *  API_synccheck,
     *  API_webwxdownloadmedia,
     *  API_webwxuploadmedia,
     *  API_webwxpreview,
     *  API_webwxinit,
     *  API_webwxgetcontact,
     *  API_webwxsync,
     *  API_webwxbatchgetcontact,
     *  API_webwxgeticon,
     *  API_webwxsendmsg,
     *  API_webwxsendmsgimg,
     *  API_webwxsendemoticon,
     *  API_webwxsendappmsg,
     *  API_webwxgetheadimg,
     *  API_webwxgetmsgimg,
     *  API_webwxgetmedia,
     *  API_webwxgetvideo,
     *  API_webwxlogout,
     *  API_webwxgetvoice,
     *  API_webwxupdatechatroom,
     *  API_webwxcreatechatroom,
     *  API_webwxstatusnotify,
     *  API_webwxcheckurl,
     *  API_webwxverifyuser,
     *  API_webwxfeedback,
     *  API_webwxreport,
     *  API_webwxsearch,
     *  API_webwxoplog;
     */

}


#endif /* end of include guard: WXAPI_HPP_QAWQCV7K */
