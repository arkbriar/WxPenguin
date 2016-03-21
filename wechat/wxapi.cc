#include "wechat.hpp"

using WxWebApi = WeChat_Http::WxWebApi;

namespace WeChat_Http {
    const WxWebApi
        Wx("https://wx.qq.com"),
        WxQRUUid("https://login.weixin.qq.com/jslogin?appid=wx782c26e4c19acffb&redirect_uri=https%3A%2F%2Fwx.qq.com%2Fcgi-bin%2Fmmwebwx-bin%2Fwebwxnewloginpage&fun=new&lang=en_US&_={##}"),
        WxQR("https://login.weixin.qq.com/qrcode/"),
        WxLoginCheck("https://login.weixin.qq.com/cgi-bin/mmwebwx-bin/login?loginicon=true&uuid={##}&tip=1&r={##}&&_={##}"),
        WxLoginCheckAfterScan("https://login.weixin.qq.com/cgi-bin/mmwebwx-bin/login?loginicon=true&uuid={##}&tip=0&r={##}&&_={##}"),
        WxInit("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxinit?r={##}&pass_ticket={##}"),
        WxIcon("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxgeticon"),
        WxHeadImg("https://wx.qq.com/"),
        WxContactList("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxgetcontact?lang=en_US&pass_ticket={##}&r={##}&seq=0&skey={##}"),
        WxContactInfo("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxbatchgetcontact?type=ex&r={##}&lang=en_US&pass_ticket={##}"),
        WxSyncCheck("https://webpush.weixin.qq.com/cgi-bin/mmwebwx-bin/synccheck?r={##}&skey={##}&sid={##}&deviceid=e762880274648329&synckey={##}"),
        WxSync("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxsync?sid={##}&skey={##}&lang=en_US&pass_ticket={##}"),
        WxSendImg(""),
        WxGetImg("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxgetmsgimg");
}
