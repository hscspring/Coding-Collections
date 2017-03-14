#-*- coding:utf-8 -*-
import sys
s = raw_input("Please input 10 numbers:")

if len(s.split(" ")) != 10:
    print("You haven't input 10 numbers.")
    print len(s)
    sys.exit(0)

for n in s.split(" "):
    if isinstance(int(n),int):
        pass
    else:
        print("You have just input some others but not numbers")
        sys.exit(0)

def myodd(number):
    if number % 2 == 0:
        pass
    else:
        return number

for n in s.split(" "):
    if myodd(int(n)) != None:
        print myodd(int(n))
