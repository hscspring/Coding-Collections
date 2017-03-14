x = 4
for i in range(0, x):
    print i
    x = 5
print x
"""
The result is 0 1 2 3, 5. x=5 do not influence range(0, x)
"""
