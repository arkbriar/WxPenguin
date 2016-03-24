#pragma once

#ifndef QTHTTP_HPP_HEPZ3VAO
#define QTHTTP_HPP_HEPZ3VAO

#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

#include "wechat/vrhttp.hpp"

namespace WxPenguin {
    namespace QtHttp {

        class QtHttpRequest : public WebWx::Http::VirtualHttpRequest {
        private:
            QNetworkRequest *r = nullptr;
        public:
            QtHttpRequest() {r = new QNetworkRequest(QUrl("")); _delegate = r;}
            virtual ~QtHttpRequest() {if(r) delete r;}

            void SetRawHeader(const std::string &headername, const std::string &headervalue) noexcept override {
                r->setRawHeader(headername.c_str(), headervalue.c_str());
            }

            void SetUrl(const std::string url) noexcept override {
                r->setUrl(QUrl::fromEncoded(url.c_str()));
            }

            using DelegateType = QNetworkRequest;
        };

        class QtHttpReply : public WebWx::Http::VirtualHttpReply {
        private:
            // QNetworkReply has a protected constructer
            QNetworkReply *r = nullptr;
        protected:
            QtHttpReply(decltype(r) r) : r(r) {}
        public:
            virtual ~QtHttpReply() {if(r) delete r;}

            std::string Url() const noexcept override {
                if(!r) return std::string();
                return r->url().toString().toStdString();
            }

            std::string Header(const std::string &key) const noexcept override {
                if(!r) return std::string();
                return r->rawHeader(key.c_str()).toStdString();
            }

            std::string Response() const noexcept override {
                if(!r) return std::string();
                return r->readAll().toStdString();
            }

            WebWx::Http::HttpError Error() const noexcept override {
                if(!r) return WebWx::Http::HttpError(-1, "reply is nullptr");
                return WebWx::Http::HttpError(r->error(), std::to_string(static_cast<int>(r->error())), QNetworkReply::NoError);
            }

            friend class QtHttpSession;
        };

        using VrRequest = WebWx::Http::VirtualHttpRequest;
        using VrReply = WebWx::Http::VirtualHttpReply;

        using VrRequestSharedPtr = std::shared_ptr<VrRequest>;
        using VrReplySharedPtr = std::shared_ptr<VrReply>;

        class QtHttpSession : public WebWx::Http::VirtualHttpSession {
        private:
            QNetworkAccessManager *m = nullptr;
        public:
            QtHttpSession() {m = new QNetworkAccessManager;}
            virtual ~QtHttpSession() {if(m) delete m;}

            VrReplySharedPtr Get(const VrRequest &request) const override {
                auto ret =  new QtHttpReply(
                        m->get(
                            *request.GetDelegate<QtHttpRequest::DelegateType>()
                            )
                        );
                return VrReplySharedPtr(ret);
            }
            VrReplySharedPtr Head(const VrRequest &request) const override {
                auto ret = new QtHttpReply(
                        m->head(
                            *request.GetDelegate<QtHttpRequest::DelegateType>()
                            )
                        );
                return VrReplySharedPtr(ret);
            }
            VrReplySharedPtr Post(const VrRequest &request, const std::string &data) const override {
                auto ret = new QtHttpReply(
                        m->post(
                            *request.GetDelegate<QtHttpRequest::DelegateType>(),
                            data.c_str()
                            )
                        );
                return VrReplySharedPtr(ret);
            }
            VrReplySharedPtr Put(const VrRequest &request, const std::string &data) const override {
                auto ret = new QtHttpReply(
                            m->put(
                                *request.GetDelegate<QtHttpRequest::DelegateType>(),
                                data.c_str()
                            )
                        );
                return VrReplySharedPtr(ret);
            }
        };

        VrRequestSharedPtr QtHttpRequestFactory();

    }
}


#endif /* end of include guard: QTHTTP_HPP_HEPZ3VAO */
