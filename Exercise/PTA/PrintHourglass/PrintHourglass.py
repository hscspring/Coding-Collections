total = 19
sign = '*'

ns = [1]
ks = [1]
n = 1
k = 1
while n < total:
    k = k + 2
    n = n + 2*k
    ns.append(n)
    ks.append(k)

if n == total:
    need_n = ns[-1]
    need_ks = ks
else:
    need_n = ns[-2]
    need_ks = ks[:-1]

remain = total - need_n
maxk = need_ks[-1]

for i in reversed(need_ks):
    print(' '*int((maxk-i)/2)+sign*i)
for i in need_ks[1:]:
    print(' '*int((maxk-i)/2)+sign*i)

print(remain)