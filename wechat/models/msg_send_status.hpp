#pragma once

#ifndef MSG_SEND_STATUS_HPP_ZAJACQUX
#define MSG_SEND_STATUS_HPP_ZAJACQUX

namespace WebWx {
    namespace Model {

        enum class MsgSendStatus {
            MSG_SEND_STATUS_READY = 0,
            MSG_SEND_STATUS_SENDING = 1,
            MSG_SEND_STATUS_SUCC = 2,
            MSG_SEND_STATUS_FAIL = 5,
        };

    }
}


#endif /* end of include guard: MSG_SEND_STATUS_HPP_ZAJACQUX */
