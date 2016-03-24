#pragma once

#ifndef UI_HANDLER_HPP_WFAQMYM2
#define UI_HANDLER_HPP_WFAQMYM2

#include "wechat/wxhandler.hpp"

namespace WxPenguin {
    namespace Ui {

        class QtUiHandler : public WebWx::WxHandler {
        public:
            QtUiHandler() {}
            ~QtUiHandler() {}

            /* on login */
            void QRload(const std::string& qr_url) const override;
            void AvatarLoad(const std::string& avatar_binary_in_base64) const override;

            /* after login */
            void WxInit(const WebWx::Model::WxInitResponse& wxres) const override;

            void ContactsRefresh(const WebWx::Model::WxGetContactResponse& wxres) const override;
            void ContactsRefresh(const WebWx::Model::WxBatchContactResponse& wxres) const override;

            void SendStatus(WebWx::Model::MsgSendStatus status) const override;

            void RecvText(const std::string& from, const std::string& to, const std::string& context) const override;
            void RecvVoice(const std::string& from, const std::string& to, const std::string& voice_url) const override;
            void RecvImage(const std::string& from, const std::string& to, const std::string& iamge_url) const override;
        };

    }
}


#endif /* end of include guard: UI_HANDLER_HPP_WFAQMYM2 */

