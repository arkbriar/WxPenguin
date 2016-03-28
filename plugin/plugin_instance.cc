#include <cassert>

#include "plugin_instance.hpp"

namespace WxPenguin {
    namespace Plugin {

        WxPluginInstance::WxPluginInstance() {}

        WxPluginInstance::WxPluginInstance(const std::string &plugin_name, const std::string &dll_name)
        : x_PluginName(plugin_name), x_DLLName(dll_name) {}

        WxPluginInstance::~WxPluginInstance() {}

        const Handler* WxPluginInstance::GetHandler() const
        {
            return hdl;
        }

        std::string WxPluginInstance::GetDLLName() const
        {
            return x_DLLName;
        }

        std::string WxPluginInstance::GetPluginName() const
        {
            return x_PluginName;
        }

        const std::vector<std::string>& WxPluginInstance::GetFunctionNames() const
        {
            return x_FunctionNames;
        }

        const std::map<std::string, std::function<void()>>& WxPluginInstance::GetFunctions() const
        {
            return x_FunctionMap;
        }

    }
}
