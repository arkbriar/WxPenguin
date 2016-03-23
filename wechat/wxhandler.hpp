#pragma once

#ifndef WXHANDLER_HPP_4FTF2GE8
#define WXHANDLER_HPP_4FTF2GE8

#include <string>

#include "models/wxmodel.hpp"
#include "models/msg_send_status.hpp"

namespace WebWx {

    class WxHandler {
    protected:
        WxHandler() {}
        virtual ~WxHandler() {};
    public:
        /* on login */
        virtual void QRload(const std::string& qr_url) = 0;
        virtual void AvatarLoad(const std::string& avatar_binary_in_base64) = 0;

        /* after login */
        virtual void WxInit(const Model::WxInitResponse& wxres) = 0;

        virtual void ContactsRefresh(const Model::WxGetContactResponse& wxres) = 0;
        virtual void ContactsRefresh(const Model::WxBatchContactResponse& wxres) = 0;

        virtual void SendStatus(Model::MsgSendStatus status);

        virtual void RecvText(const std::string& from, const std::string& to, const std::string& context) = 0;
        virtual void RecvVoice(const std::string& from, const std::string& to, const std::string& voice_url) = 0;
        virtual void RecvImage(const std::string& from, const std::string& to, const std::string& iamge_url) = 0;

    };

}


#endif /* end of include guard: WXHANDLER_HPP_4FTF2GE8 */
