#!/usr/bin/python
# encoding=utf-8

import os
import sys

BASEDIR = os.path.dirname(os.path.abspath(__file__))
PROBEDIR = os.path.join(BASEDIR, 'js/probe')

def cmd_create(pid, c):
    pf = os.path.join(PROBEDIR, '%s.js'%pid)
    cf = os.path.join(PROBEDIR, '%s.cmd'%pid)
    if not os.path.exists(pf):
        print('%s.js probe must be created first.'%pid)
        return 0

    if os.path.exists(cf):
        f = open(cf)
        _c = f.read().strip()
        f.close()
        if _c:
            yn = raw_input('%s.cmd has been existed, overwrite it? y/n: '%pid)
            if str(yn).lower() != 'y':
                return 0

    f = open(cf, 'w')
    f.write(c)
    f.close()
    
    print('%s created ok.'%cf)
    return 1

if __name__ == '__main__':
    try:
        pid = sys.argv[1]
        cmdf = sys.argv[2]
    except:
        print('Usage: ./cmd_create.py pid cmdfile\nargv pid must be isalnum, argv cmdfile must contain js code')
        sys.exit(0)
    if not pid.isalnum():
        print('argv pid must be isalnum')
        sys.exit(0)

    try:
        f = open(cmdf)
        c = f.read()
        f.close()
    except:
        print('%s not found.'%cmdf)
        sys.exit(0)
    
    cmd_create(pid, c)
    
