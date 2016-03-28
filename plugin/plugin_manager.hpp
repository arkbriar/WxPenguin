#ifndef PLUGIN_MANAGER_HPP_BFJ0XW9R
#define PLUGIN_MANAGER_HPP_BFJ0XW9R

#include <string>
#include <vector>
#include <map>
#include <functional>

#include "macros.h"

namespace WxPenguin {
    namespace Plugin {
        class WxPluginInstance;
        class DynamicLib;

        class DLL_PUBLIC WxPluginManager {
        public:
            using WxPluginInstancePtr = WxPluginInstance *;
            using DynamicLibPtr = DynamicLib *;
            using P_D_List = std::map<std::string, std::string>;

            // Singleton
            static WxPluginManager& GetManager();

            bool LoadAll();

            // err_code equals to
            // 0, when ok
            // -1, entry function not found
            // -2, should never be this val. If you found err_code == -2, please report an issue
            WxPluginInstance* Load(const std::string &plugin_name, const std::string &dll_name, int &err_code);

            bool LoadPlugin(WxPluginInstance *plugin);

            bool UnLoadAll();

            bool UnLoad(const std::string &plugin_name);

            bool UnLoadPlugin(WxPluginInstance *plugin);

            const std::vector<WxPluginInstancePtr>& GetAllPlugins() const;

            P_D_List ReadConf() const;

        private:
            // initialize with an empty ReadConf_
            std::function<P_D_List ()> ReadConf_ = std::function<P_D_List ()>([] () { return P_D_List(); });

            WxPluginManager() {}
            ~WxPluginManager() {}
            static WxPluginManager Manager_;

            std::vector<WxPluginInstancePtr> Plugins_;
            // map plugins' name to instance
            std::map<std::string, WxPluginInstancePtr> InstanceMap_;
            // map plugins' name to dynamic libs
            std::map<std::string, DynamicLibPtr> DynamicLibMap_;
        };

    }
}


#endif /* end of include guard: PLUGIN_MANAGER_HPP_BFJ0XW9R */
