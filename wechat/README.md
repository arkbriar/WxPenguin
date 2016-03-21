Wechat Module in C++
====================

# Intro

A flexiable, extendable library of web wechat client.

# Doc

## Abstract Classes

> Http Request

```cpp
    class VirtualHttpRequest {
    public:
        VirtualHttpRequest() {}
        virtual ~VirtualHttpRequest() = 0;

        virtual void SetRawHeader(const std::string &headername, const std::string &headervalue) noexcept = 0;
        virtual void SetUrl(const std::string url) noexcept = 0;
    };
```

> Http Reply

```cpp
    class VirtualHttpReply {
    public:
        VirtualHttpReply() {}
        virtual ~VirtualHttpReply() = 0;

        virtual std::string Url() const noexcept = 0;
        virtual std::string Header(const std::string &key) const noexcept = 0;
        virtual std::uint64_t Status() const noexcept = 0;
        virtual std::string Response() const noexcept = 0;
        virtual HttpError Error() const noexcept = 0;
    };
```

> Http Session/Manager

```cpp
    class VirtualHttpSession {
    public:
        VirtualHttpSession() {}
        virtual ~VirtualHttpSession() = 0;

        virtual std::shared_ptr<VirtualHttpReply> Get(const VirtualHttpRequest &request) const = 0;
        virtual std::shared_ptr<VirtualHttpReply> Head(const VirtualHttpRequest &request) const = 0;
        virtual std::shared_ptr<VirtualHttpReply> Post(const VirtualHttpRequest &request, std::string data) const = 0;
        virtual std::shared_ptr<VirtualHttpReply> Put(const VirtualHttpRequest &request, std::string data) const = 0;

        virtual std::string GetCookieValue(const std::string key) const = 0;
    };
```

> Wechat Handler (ui)

```cpp
    class WxHandler {
    protected:
        WxHandler() {}
        virtual ~WxHandler() {};
    public:
        /* on login */
        virtual void QRload(const std::string& qr_url) = 0;
        virtual void AvatarLoad(const std::string& avatar) = 0;

        /* after login */
        virtual void WxInit(const std::string& json_string) = 0;
        virtual void ContactsRefresh() = 0;
        virtual void ChatRefresh(const std::string& username, const std::string& context) = 0;
        virtual void Voice(const std::string& voice_url) = 0;
        virtual void Image(const std::string& iamge_url) = 0;
    };
```

## Abstract Factory

> VrRequest Factory

```cpp
    std::shared_ptr<VirtualHttpRequest> NewVirtualHttpRequest_NULLPTR();
    using VrReqFactory = decltype(WeChat_Http::NewVirtualHttpRequest_NULLPTR);
```

