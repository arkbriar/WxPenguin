#pragma once

#ifndef WX_BASEREQUEST_HPP_KNEZVOGN
#define WX_BASEREQUEST_HPP_KNEZVOGN

#include <string>

#include "../json/json.hpp"

namespace WebWx {
    namespace Model {

        class WxBaseRequest {
            const std::string DeviceID = "e762880274648329";

        public:
            WxBaseRequest() {}
            WxBaseRequest(const std::string& Uin, const std::string Sid, std::string Skey)
                : Uin(Uin), Sid(Sid), Skey(Skey) {}

            std::string Uin;
            std::string Sid;
            std::string Skey;

            nlohmann::json GetJson() const {
                nlohmann::json ret;

                ret["Uin"] = Uin;
                ret["Sid"] = Sid;
                ret["Skey"] = Skey;
                ret["DeviceID"] = DeviceID;

                return ret;
            }

            const std::string& GetDeviceID() const {
                return DeviceID;
            }
        };

    }
}


#endif /* end of include guard: WX_BASEREQUEST_HPP_KNEZVOGN */
