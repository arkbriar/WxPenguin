#pragma once

#ifndef WX_CONTACT_HPP_1X5PRBIK
#define WX_CONTACT_HPP_1X5PRBIK

#include <string>
#include <vector>

#include "../json/json.hpp"

namespace WebWx {
    namespace Model {

        class WxContact {
        public:
            class WxMember {
            public:
                WxMember();
                WxMember(const nlohmann::json&);

                int Uin;
                std::string UserName;
                std::string NickName;
                int AttrStatus;
                std::string PYInitial;
                std::string PYQuanPin;
                std::string RemarkPYInitial;
                std::string RemarkPYQuanPin;
                int MemberStatus;
                std::string DisplayName;
                std::string KeyWord;
            };

            WxContact();
            WxContact(const nlohmann::json&);
            bool IsGroup() const {return MemberCount != 0;}

            int Uin;
            std::string UserName;
            std::string NickName;
            std::string HeadImgUrl;
            int ContactFlag;
            int MemberCount;
            std::vector<WxMember> MemberList;
            std::string RemarkName;
            int Sex;
            std::string Signature;
            int VerifyFlag;
            std::string PYInitial;
            std::string PYQuanPin;
            std::string RemarkPYInitial;
            std::string RemarkPYQuanPin;
            int StarFriend;
            int AppAcountFlag;
            int Statues;
            int AttrStatus;
            std::string Province;
            std::string City;
            std::string Alias;
            int SnsFlag;
            int UniFriend;
            std::string DisplayName;
            int ChatRoomId;
            std::string KeyWord;
            std::string EncryChatRoomId;
        };

    }
}


#endif /* end of include guard: WX_CONTACT_HPP_1X5PRBIK */
