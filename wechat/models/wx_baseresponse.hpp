#pragma once

#ifndef WX_BASERESPONSE_HPP_FBKOZJDZ
#define WX_BASERESPONSE_HPP_FBKOZJDZ

#include <string>

#include "../json/json.hpp"

namespace WebWx {
    namespace Model {

        class WxBaseResponse {
        public:
            WxBaseResponse();
            WxBaseResponse(const nlohmann::json&);

            int Ret;
            std::string ErrMsg;
        };

    }
}


#endif /* end of include guard: WX_BASERESPONSE_HPP_FBKOZJDZ */
