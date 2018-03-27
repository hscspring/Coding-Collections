#!/usr/bin/python
# encoding=utf-8

import os
import sys

BASEDIR = os.path.dirname(os.path.abspath(__file__))
PROBEDIR = os.path.join(BASEDIR, 'js/probe')

def probe_create(pid, cmdaddress):
    pf = os.path.join(PROBEDIR, '%s.js'%pid)
    if os.path.exists(pf):
        yn = raw_input('%s.js has been existed, overwrite it? y/n: '%pid)
        if str(yn).lower() != 'y':
            return 0
    
    f = open(os.path.join(BASEDIR, 'js/payload/probe.js'))
    c = f.read()
    f.close()
    c = c.replace('abcdefg', pid)
    c = c.replace('cmdaddress', cmdaddress)
    f = open(pf, 'w')
    f.write(c)
    f.close()

    print('%s created ok.'%pf)
    return 1

if __name__ == '__main__':
    try:
        pid = sys.argv[1]
        cmdaddress = sys.argv[2]
    except:
        print('Usage: ./probe_create.py pid cmdaddress\nargv pid must be isalnum, argv cmdaddress must startswith http:// or https:// and with host end, eg:\n./probe_create.py a1 http://test.com\n./probe_create.py a1 https://test.com')
        sys.exit(0)
    if not pid.isalnum():
        print('argv pid must be isalnum')
        sys.exit(0)
    if not cmdaddress.lower().startswith(('http://', 'https://')):
        print('argv cmdaddress must startswith http:// or https://')
        sys.exit(0)
    
    probe_create(pid, cmdaddress)
    
