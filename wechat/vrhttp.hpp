#pragma once

#ifndef VRHTTP_HPP_OX1KUYLI
#define VRHTTP_HPP_OX1KUYLI

/* Here is the virtual http class for WeChat web api.
 * */

#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <utility>

namespace WeChat_Http {

    class VirtualHttpRequest {
    public:
        VirtualHttpRequest() {}
        virtual ~VirtualHttpRequest() = 0;

        virtual void SetRawHeader(const std::string &headername, const std::string &headervalue) noexcept = 0;
        virtual void SetUrl(const std::string url) noexcept = 0;
    };

    VirtualHttpRequest* NewVirtualHttpRequest_NULLPTR() {
        return nullptr;
    }

    VirtualHttpRequest::~VirtualHttpRequest() {}

    class HttpError {
    public:
        HttpError() : error(0) {}

        template <
            typename ErrorCodeType,
            typename std::enable_if<std::is_enum<ErrorCodeType>::value, int>::type = 0
            >
        HttpError(const ErrorCodeType code, const std::string& error_message)
            : error((std::int64_t)code), message(error_message) {}

        explicit operator bool() const {
            return error == 0;
        }

        template <
            typename ErrorCodeType,
            typename std::enable_if<std::is_enum<ErrorCodeType>::value, int>::type = 0
            >
        bool operator == (const ErrorCodeType code) {
            return std::int64_t(code) == 0;
        }

        bool operator == (const std::int64_t code) {
            return code == error;
        }

        template <
            typename ErrorCodeType,
            typename std::enable_if<std::is_enum<ErrorCodeType>::value, int>::type = 0
            >
        ErrorCodeType Error() {
            return (ErrorCodeType)error;
        }

        std::int64_t Error() {
            return error;
        }

        const std::string& ErrorMessage() const noexcept {
            return message;
        }

    private:
        std::int64_t error;
        std::string message;
    };

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

    VirtualHttpReply::~VirtualHttpReply() {}

    class VirtualHttpSession {
    public:
        VirtualHttpSession() {}
        virtual ~VirtualHttpSession() = 0;

        virtual VirtualHttpReply* Get(const VirtualHttpRequest &request) const = 0;
        virtual VirtualHttpReply* Head(const VirtualHttpRequest &request) const = 0;
        virtual VirtualHttpReply* Post(const VirtualHttpRequest &request, std::string data) const = 0;
        virtual VirtualHttpReply* Post(const VirtualHttpRequest &request, std::map<std::string, std::string> data) const = 0;
        virtual VirtualHttpReply* Put(const VirtualHttpRequest &request, std::string data) const = 0;
    };

    VirtualHttpSession::~VirtualHttpSession() {}
}

#endif /* end of include guard: VRHTTP_HPP_OX1KUYLI */
