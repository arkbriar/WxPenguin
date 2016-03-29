#ifndef PLUGIN_INSTANCE_HPP_W9NVACIY
#define PLUGIN_INSTANCE_HPP_W9NVACIY

#include <string>
#include <map>
#include <vector>
#include <functional>

#include "macros.h"

#include "wxplugin.hpp"

namespace WxPenguin {
    namespace Plugin {

        // interface of ui/wx/other handlers
        class Handler;

        class WxPluginManager;

        class DLL_PUBLIC WxPluginInstance {
        public:
            explicit WxPluginInstance();
            explicit WxPluginInstance(const std::string &plugin_name, const std::string &dll_name);
            virtual ~WxPluginInstance();

            virtual bool Load() = 0;

            virtual bool IsLoad() = 0;

            virtual bool UnLoad() = 0;

            // xxx.dll or xxx.so, will only return xxx
            std::string GetDLLName() const;

            // xxx
            std::string GetPluginName() const;

            const std::vector<std::string>& GetFunctionNames() const;

            const std::map<std::string, std::function<void()>>& GetFunctions() const;

            const Handler* GetHandler() const;

        protected:
            const std::string x_PluginName;
            const std::string x_DLLName;

            std::vector<std::string> x_FunctionNames;
            std::map<std::string, std::function<void()>> x_FunctionMap;

            // all ui/wx/other handlers can be used here;
            Handler* hdl = nullptr;
            // manager will set the hdl for every instance;
            friend class WxPluginManager;

        private:
            /* The 4 functions followed will not be implemented */
            WxPluginInstance(const WxPluginInstance &other);
            WxPluginInstance(WxPluginInstance &&other);

            // copy assignment
            WxPluginInstance& operator =(WxPluginInstance &other);
            // move assignment
            WxPluginInstance& operator =(WxPluginInstance &&other);
        };

        typedef WxPluginInstance* (*WxPluginStartFunc) ();
        typedef void (*WxPluginStopFunc) ();

    }
}


#endif /* end of include guard: PLUGIN_INSTANCE_HPP_W9NVACIY */
