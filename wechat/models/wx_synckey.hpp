#pragma once

#ifndef WX_SYNCKEY_HPP_1Z6TPOWO
#define WX_SYNCKEY_HPP_1Z6TPOWO

#include <string>

#include "../json/json.hpp"

namespace WebWx {
    namespace Model {

        class WxSyncKey {
        public:
            //@no impl/
            WxSyncKey() {}
            WxSyncKey(const nlohmann::json&) {}
        };

    }
}


#endif /* end of include guard: WX_SYNCKEY_HPP_1Z6TPOWO */
