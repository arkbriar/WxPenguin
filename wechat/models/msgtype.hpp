#pragma once

#ifndef MSGTYPE_HPP_IHDCUGJA
#define MSGTYPE_HPP_IHDCUGJA

namespace WebWx {
    namespace Model {

        enum class MsgType {
            MSGTYPE_TEXT = 1,
            MSGTYPE_IMAGE = 3,
            MSGTYPE_VOICE = 34,
            MSGTYPE_VIDEO = 43,
            MSGTYPE_MICROVIDEO = 62,
            MSGTYPE_EMOTICON = 47,
            MSGTYPE_APP = 49,
            MSGTYPE_VOIPMSG = 50,
            MSGTYPE_VOIPNOTIFY = 52,
            MSGTYPE_VOIPINVITE = 53,
            MSGTYPE_LOCATION = 48,
            MSGTYPE_STATUSNOTIFY = 51,
            MSGTYPE_SYSNOTICE = 9999,
            MSGTYPE_POSSIBLEFRIEND_MSG = 40,
            MSGTYPE_VERIFYMSG = 37,
            MSGTYPE_SHARECARD = 42,
            MSGTYPE_SYS = 10000,
            MSGTYPE_RECALLED = 10002
        };

        enum class StatusNotifyCode {
            StatusNotifyCode_READED = 1,
            StatusNotifyCode_ENTER_SESSION = 2,
            StatusNotifyCode_INITED = 3,
            StatusNotifyCode_SYNC_CONV = 4,
            StatusNotifyCode_QUIT_SESSION = 5,
        };
    }
}


#endif /* end of include guard: MSGTYPE_HPP_IHDCUGJA */
