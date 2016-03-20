#include "wechat.hpp"

using WxWebApi = WeChat_Http::WxWebApi;

namespace WeChat_Http {
    WxWebApi
        Wx("https://wx.qq.com/"),
        WxQRUUid("https://login.weixin.qq.com/jslogin?appid=wx782c26e4c19acffb&redirect_uri=https%3A%2F%2Fwx.qq.com%2Fcgi-bin%2Fmmwebwx-bin%2Fwebwxnewloginpage&fun=new&lang=en_US"),
        WxQR("https://login.weixin.qq.com/qrcode/"),
        WxLoginCheck("https://login.weixin.qq.com/cgi-bin/mmwebwx-bin/login?loginicon=true&uuid=oY-zWuGYzA==&tip=0&r=1824241377"),
        WxInit("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxinit?r=1823965664"),
        WxIcon("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxgeticon"),
        WxHeadImg("https://wx.qq.com/"),
        WxContact("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxbatchgetcontact"),
        WxSyncCheck("https://webpush.weixin.qq.com/cgi-bin/mmwebwx-bin/synccheck"),
        WxSync("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxsync"),
        WxSendImg("");
}
