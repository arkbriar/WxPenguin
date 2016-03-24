#pragma once

#ifndef VRHTTP_HPP_OX1KUYLI
#define VRHTTP_HPP_OX1KUYLI

/* Here is the virtual http class for WeChat web api.
 * */

#include <string>
#include <map>
#include <cstdint>
#include <memory>

namespace WebWx {
    namespace Http {

        template <typename _DelegateType>
        class _VirtualHttpRequest {
        public:
            _VirtualHttpRequest() {}
            virtual ~_VirtualHttpRequest() {}

            virtual void SetRawHeader(const std::string &headername, const std::string &headervalue) noexcept = 0;
            virtual void SetUrl(const std::string url) noexcept = 0;

            template <typename T>
                const T* GetDelegate() const {return static_cast<T*>(_delegate);}
        protected:
            _DelegateType *_delegate = nullptr;
        };

        using VirtualHttpRequest = _VirtualHttpRequest<void>;

        std::shared_ptr<VirtualHttpRequest> NewVirtualHttpRequest_NULLPTR();

        class HttpError {
        public:
            HttpError() : error(0), ok(0) {}

            HttpError(std::uint64_t code, const std::string& error_message)
                : error(code), message(error_message), ok(0) {}
            HttpError(std::uint64_t code, const char* error_message)
                : error(code), message(error_message), ok(0) {}

            template <
                typename ErrorCodeType,
                typename std::enable_if<std::is_enum<ErrorCodeType>::value, int>::type = 0
                >
            HttpError(const ErrorCodeType code, const std::string& error_message, const ErrorCodeType ok = static_cast<ErrorCodeType>(0))
                : error(static_cast<std::int64_t>(code)), message(error_message), ok(static_cast<std::int64_t>(ok)) {}

            template <
                typename ErrorCodeType,
                typename std::enable_if<std::is_enum<ErrorCodeType>::value, int>::type = 0
                >
            HttpError(const ErrorCodeType code, const char* error_message, const ErrorCodeType ok = static_cast<ErrorCodeType>(0))
                : error(static_cast<std::int64_t>(code)), message(error_message), ok(static_cast<std::int64_t>(ok)) {}

            explicit operator bool() const {
                return error != ok;
            }

            template <
                typename ErrorCodeType,
                typename std::enable_if<std::is_enum<ErrorCodeType>::value, int>::type = 0
                >
            bool operator == (const ErrorCodeType code) {
                return std::int64_t(code) == error;
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

            const std::int64_t ok;
        };

        class VirtualHttpReply {
        public:
            VirtualHttpReply() {}
            virtual ~VirtualHttpReply() = 0;

            virtual std::string Url() const noexcept = 0;
            virtual std::string Header(const std::string &key) const noexcept = 0;
            virtual std::string Response() const noexcept = 0;
            virtual HttpError Error() const noexcept = 0;

            virtual std::string Cookie(const std::string& key) const noexcept = 0;
        };

        class VirtualHttpSession {
        public:
            VirtualHttpSession() {}
            virtual ~VirtualHttpSession() = 0;

            virtual std::shared_ptr<VirtualHttpReply> Get(const VirtualHttpRequest &request) const = 0;
            virtual std::shared_ptr<VirtualHttpReply> Head(const VirtualHttpRequest &request) const = 0;
            virtual std::shared_ptr<VirtualHttpReply> Post(const VirtualHttpRequest &request, const std::string &data) const = 0;
            virtual std::shared_ptr<VirtualHttpReply> Put(const VirtualHttpRequest &request, const std::string &data) const = 0;
        };

    }
}

#endif /* end of include guard: VRHTTP_HPP_OX1KUYLI */
