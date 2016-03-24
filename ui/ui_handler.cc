#include "ui_handler.hpp"

using namespace WebWx::Model;

namespace WxPenguin {
    namespace Ui {

        void QtUiHandler::QRload(const std::string& qr_url) const
        {
        }

        void QtUiHandler::AvatarLoad(const std::string& avatar_binary_in_base64) const
        {
        }

        void QtUiHandler::WxInit(const WxInitResponse& wxres) const
        {
        }

        void QtUiHandler::ContactsRefresh(const WxGetContactResponse& wxres) const
        {
        }

        void QtUiHandler::ContactsRefresh(const WxBatchContactResponse& wxres) const
        {
        }

        void QtUiHandler::SendStatus(MsgSendStatus status) const
        {
        }

        void QtUiHandler::RecvText(const std::string& from, const std::string& to, const std::string& context) const
        {
        }

        void QtUiHandler::RecvVoice(const std::string& from, const std::string& to, const std::string& voice_url) const
        {
        }

        void QtUiHandler::RecvImage(const std::string& from, const std::string& to, const std::string& iamge_url) const
        {
        }

    }
}
