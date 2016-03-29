Plugin Module
=====================

# Intro

Plugin core of wechat client.

# Doc

## Plugin Manager

```cpp

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
```

## Abstract Plugin Instance
```cpp

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
```

## Entry functions
```cpp
extern "C" DLL_PUBLIC WxPluginInstance *__WxPluginStart();

extern "C" DLL_PUBLIC void __WxPluginStop();
```
