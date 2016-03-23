#include "wxapi.hpp"

using WxWebAPI = WebWx::WxWebAPI;

namespace WebWx {
    const WxWebAPI
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
        WxGetImg("https://wx.qq.com/cgi-bin/mmwebwx-bin/webwxsendmsg?lang=en_US&pass_ticket={##}");

    /*
     *const WxWebAPI
     *  API_jsLogin,
     *  API_login,
     *  API_synccheck,
     *  API_webwxdownloadmedia,
     *  API_webwxuploadmedia,
     *  API_webwxpreview,
     *  API_webwxinit,
     *  API_webwxgetcontact,
     *  API_webwxsync,
     *  API_webwxbatchgetcontact,
     *  API_webwxgeticon,
     *  API_webwxsendmsg,
     *  API_webwxsendmsgimg,
     *  API_webwxsendemoticon,
     *  API_webwxsendappmsg,
     *  API_webwxgetheadimg,
     *  API_webwxgetmsgimg,
     *  API_webwxgetmedia,
     *  API_webwxgetvideo,
     *  API_webwxlogout,
     *  API_webwxgetvoice,
     *  API_webwxupdatechatroom,
     *  API_webwxcreatechatroom,
     *  API_webwxstatusnotify,
     *  API_webwxcheckurl,
     *  API_webwxverifyuser,
     *  API_webwxfeedback,
     *  API_webwxreport,
     *  API_webwxsearch,
     *  API_webwxoplog;
     */

    /*
      API_jsLogin: "https://login." + t + "/jslogin?appid=wx782c26e4c19acffb&redirect_uri=" + encodeURIComponent(location.protocol + "//" + location.host + "/cgi-bin/mmwebwx-bin/webwxnewloginpage") + "&fun=new&lang=" + r,
      API_login: "https://login." + t + "/cgi-bin/mmwebwx-bin/login",
      API_synccheck: "https://" + n + "/cgi-bin/mmwebwx-bin/synccheck",
      API_webwxdownloadmedia: "https://" + o + "/cgi-bin/mmwebwx-bin/webwxgetmedia",
      API_webwxuploadmedia: "https://" + o + "/cgi-bin/mmwebwx-bin/webwxuploadmedia",
      API_webwxpreview: "/cgi-bin/mmwebwx-bin/webwxpreview",
      API_webwxinit: "/cgi-bin/mmwebwx-bin/webwxinit?r=" + ~new Date,
      API_webwxgetcontact: "/cgi-bin/mmwebwx-bin/webwxgetcontact",
      API_webwxsync: "/cgi-bin/mmwebwx-bin/webwxsync",
      API_webwxbatchgetcontact: "/cgi-bin/mmwebwx-bin/webwxbatchgetcontact",
      API_webwxgeticon: "/cgi-bin/mmwebwx-bin/webwxgeticon",
      API_webwxsendmsg: "/cgi-bin/mmwebwx-bin/webwxsendmsg",
      API_webwxsendmsgimg: "/cgi-bin/mmwebwx-bin/webwxsendmsgimg",
      API_webwxsendemoticon: "/cgi-bin/mmwebwx-bin/webwxsendemoticon",
      API_webwxsendappmsg: "/cgi-bin/mmwebwx-bin/webwxsendappmsg",
      API_webwxgetheadimg: "/cgi-bin/mmwebwx-bin/webwxgetheadimg",
      API_webwxgetmsgimg: "/cgi-bin/mmwebwx-bin/webwxgetmsgimg",
      API_webwxgetmedia: "/cgi-bin/mmwebwx-bin/webwxgetmedia",
      API_webwxgetvideo: "/cgi-bin/mmwebwx-bin/webwxgetvideo",
      API_webwxlogout: "/cgi-bin/mmwebwx-bin/webwxlogout",
      API_webwxgetvoice: "/cgi-bin/mmwebwx-bin/webwxgetvoice",
      API_webwxupdatechatroom: "/cgi-bin/mmwebwx-bin/webwxupdatechatroom",
      API_webwxcreatechatroom: "/cgi-bin/mmwebwx-bin/webwxcreatechatroom",
      API_webwxstatusnotify: "/cgi-bin/mmwebwx-bin/webwxstatusnotify",
      API_webwxcheckurl: "/cgi-bin/mmwebwx-bin/webwxcheckurl",
      API_webwxverifyuser: "/cgi-bin/mmwebwx-bin/webwxverifyuser",
      API_webwxfeedback: "/cgi-bin/mmwebwx-bin/webwxsendfeedback",
      API_webwxreport: "/cgi-bin/mmwebwx-bin/webwxstatreport",
      API_webwxsearch: "/cgi-bin/mmwebwx-bin/webwxsearchcontact",
      API_webwxoplog: "/cgi-bin/mmwebwx-bin/webwxoplog",
     */

}
