#ifndef PLUGIN_INSTANCE_HPP_W9NVACIY
#define PLUGIN_INSTANCE_HPP_W9NVACIY

#include <string>

#include "macros.h"

namespace WxPenguin {
    namespace Plugin {

        class DLL_PUBLIC WxPluginInstance {
        public:
            explicit WxPluginInstance(const std::string &plugin_name);
            virtual ~WxPluginInstance();

            virtual bool Load() = 0;

            virtual bool UnLoad() = 0;

            // xxx.dll or xxx.so
            virtual std::string GetFileName() const = 0;

            // xxx
            virtual std::string GetPluginName() const = 0;

        private:
            /* The 4 functions followed will not be implemented */
            WxPluginInstance(const WxPluginInstance &other);
            WxPluginInstance(WxPluginInstance &&other);

            // copy assignment
            WxPluginInstance& operator =(WxPluginInstance &other);
            // move assignment
            WxPluginInstance& operator =(WxPluginInstance &&other);
        };

    }
}


#endif /* end of include guard: PLUGIN_INSTANCE_HPP_W9NVACIY */
