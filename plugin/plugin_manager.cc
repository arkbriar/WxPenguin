#include <cassert>

#include "plugin_manager.hpp"
#include "dynamiclib.hpp"
#include "plugin_instance.hpp"

namespace WxPenguin {
    namespace Plugin {

        WxPluginManager& WxPluginManager::GetManager()
        {
            return Manager_;
        }

        bool WxPluginManager::LoadAll()
        {
            bool ret = true;
            for (auto i : Plugins_) {
                ret = ret && LoadPlugin(i);
            }
            return ret;
        }

        WxPluginInstance* WxPluginManager::Load(const std::string &plugin_name, const std::string &dll_name, int &err_code)
        {
            auto it = DynamicLibMap_.find(plugin_name);
            if (it == DynamicLibMap_.end()) { // not found
                DynamicLib* lib = new DynamicLib;
                if(lib) {
                    // load dll
                    lib->LoadLib(dll_name.c_str());

                    // get entry function
                    WxPluginStartFunc start = (WxPluginStartFunc)lib->GetSymbolAddress("__WxPluginStart");
                    if (start) {
                        auto plugin = start();
                        InstanceMap_.insert(std::make_pair(plugin_name, plugin));
                        DynamicLibMap_.insert(std::make_pair(plugin_name, lib));
                        Plugins_.push_back(plugin);
                        err_code = 0;
                        return plugin;
                    } else {
                        err_code = -1;
                        return nullptr;
                    }
                }
            } else { // found
                err_code = 0;
                return InstanceMap_[plugin_name];
            }

            // should never reach here
            err_code = -2;
            return nullptr;
        }

        bool WxPluginManager::LoadPlugin(WxPluginInstance *plugin)
        {
            return plugin->Load();
        }

        bool WxPluginManager::UnLoadAll()
        {
            bool ret = true;
            for (auto i : Plugins_) {
                ret = ret && UnLoadPlugin(i);
            }
            return ret;
        }

        bool WxPluginManager::UnLoad(const std::string &plugin_name)
        {
            auto it = DynamicLibMap_.find(plugin_name);
            auto it_sec = InstanceMap_.find(plugin_name);

            assert(it != DynamicLibMap_.end() && it_sec != InstanceMap_.end());

            auto lib = it->second;
            auto plugin = it_sec->second;
            if (lib != nullptr && plugin != nullptr) {
                // should be unloaded first
                if (plugin->IsLoad()) return false;

                WxPluginStopFunc stop = (WxPluginStopFunc)lib->GetSymbolAddress("__WxPluginStop");
                if (stop) stop();

                lib->FreeLib();
                delete lib;

                DynamicLibMap_.erase(it);
                InstanceMap_.erase(it_sec);
                return true;
            }

            return false;

        }

        bool WxPluginManager::UnLoadPlugin(WxPluginInstance *plugin)
        {
            return plugin->UnLoad();
        }

        const std::vector<WxPluginManager::WxPluginInstancePtr>& WxPluginManager::GetAllPlugins() const
        {
            return Plugins_;
        }

        WxPluginManager::P_D_List WxPluginManager::ReadConf() const
        {
            return ReadConf_();
        }
    }
}
