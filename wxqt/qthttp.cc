#include "qthttp.hpp"

namespace WxPenguin {
    namespace QtHttp {

        VrRequestSharedPtr QtHttpRequestFactory()
        {
            return VrRequestSharedPtr(new QtHttpRequest);
        }

    }
}
