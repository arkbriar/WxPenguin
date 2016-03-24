#include <string.h>
#include <string>

#include "dynamiclib.hpp"

using namespace WxPenguin::Plugin;

#if defined(__unix__) || defined(unix)
#include <dlfcn.h>

bool DynamicLib::LoadLib(const char* lib_name)
{
    std::string s = lib_name;
    s += ".so";
    h_DynamicLib = dlopen(s.c_str(), RTLD_LAZY);
    if(h_DynamicLib == nullptr) return false;

    _LibName = strdup(lib_name);

    return true;
}

void* DynamicLib::GetSymbolAddress(const char* symbol_name) const
{
    void *pSymbol = nullptr;

    if (h_DynamicLib) {
        pSymbol = dlsym(h_DynamicLib, symbol_name);
    }

    return pSymbol;
}

void DynamicLib::FreeLib()
{
    if (h_DynamicLib) {
        dlclose(h_DynamicLib);
        h_DynamicLib = nullptr;
    }

    if (_LibName) {
        delete _LibName;
        _LibName = nullptr;
    }
}

#endif

#ifdef _WIN32
#include <Windows.h>

bool DynamicLib::LoadLib(const char* lib_name)
{
}

void* DynamicLib::GetSymbolAddress(const char* symbol_name) const
{

}

void DynamicLib::FreeLib()
{

}

#endif

