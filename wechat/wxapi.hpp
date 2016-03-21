#pragma once

#ifndef WXAPI_HPP_QAWQCV7K
#define WXAPI_HPP_QAWQCV7K

#include <string>

namespace WeChat_Http {

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
}


#endif /* end of include guard: WXAPI_HPP_QAWQCV7K */
