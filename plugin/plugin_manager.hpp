#ifndef PLUGIN_MANAGER_HPP_BFJ0XW9R
#define PLUGIN_MANAGER_HPP_BFJ0XW9R

#include <string>
#include <vector>
#include <map>

#include "macros.h"

namespace WxPenguin {
    namespace Plugin {
        class WxPluginInstance;
        class DynamicLib;

        class DLL_PUBLIC WxPluginManager {
        public:
            using WxPluginInstancePtr = WxPluginInstance *;
            using DynamicLibPtr = DynamicLib *;

            static WxPluginManager& GetManager();

            bool LoadAll() const;

            WxPluginInstance* Load(const std::string &plugin_name, int &err_code);

            bool LoadPlugin(WxPluginInstance *plugin);

            bool UnLoadAll();

            bool Unload(const std::string &plugin_name);

            bool UnLoadPlugin(WxPluginInstance *plugin);

            std::vector<WxPluginInstancePtr> GetAllPlugins() const;

        private:
            WxPluginManager() {}
            ~WxPluginManager() {}
            static WxPluginManager _Manager;

            std::vector<WxPluginInstancePtr> _Plugins;
            std::map<std::string, DynamicLibPtr> _DynamicLibs;
        };

    }
}


#endif /* end of include guard: PLUGIN_MANAGER_HPP_BFJ0XW9R */
