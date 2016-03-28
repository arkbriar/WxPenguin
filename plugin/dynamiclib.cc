#include <string.h>
#include <string>

#include "dynamiclib.hpp"

using namespace WxPenguin::Plugin;

DynamicLib::DynamicLib() {}

DynamicLib::~DynamicLib()
{
    if (h_DynamicLib) FreeLib();
    if (x_LibName) {
        delete x_LibName;
        x_LibName = nullptr;
    }
}

const char* DynamicLib::GetName() const
{
    return x_LibName;
}

#if defined(__unix__) || defined(unix)
#include <dlfcn.h>

bool DynamicLib::LoadLib(const char* lib_name)
{
    std::string s = lib_name;
    s += ".so";
    h_DynamicLib = dlopen(s.c_str(), RTLD_LAZY);
    if(h_DynamicLib == nullptr) return false;

    x_LibName = strdup(lib_name);

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

    if (x_LibName) {
        delete x_LibName;
        x_LibName = nullptr;
    }
}

#endif // unix

#ifdef _WIN32
#include <Windows.h>

bool DynamicLib::LoadLib(const char* lib_name)
{
    std::string s = lib_name;
    s += ".dll";
    h_DynamicLib = LoadLibrary(s.c_str());
    if(h_DynamicLib) {
        x_LibName = strdup(lib_name);
        return true;
    }

    return false;
}

void* DynamicLib::GetSymbolAddress(const char* symbol_name) const
{
    if (h_DynamicLib) {
        return (void*) GetProcAddress((HMODULE)h_DynamicLib, symbol_name);
    }

    return nullptr;
}

void DynamicLib::FreeLib()
{
    if (h_DynamicLib) {
        FreeLibrary((HMODULE)h_DynamicLib);
        h_DynamicLib = nullptr;
    }

    if (x_LibName) {
        delete x_LibName;
        x_LibName = nullptr;
    }
}

#endif // _WIN32

