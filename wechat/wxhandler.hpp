#pragma once

#ifndef WXHANDLER_HPP_4FTF2GE8
#define WXHANDLER_HPP_4FTF2GE8

#include <string>

namespace WebWx {

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

}


#endif /* end of include guard: WXHANDLER_HPP_4FTF2GE8 */
