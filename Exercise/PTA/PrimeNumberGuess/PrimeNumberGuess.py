import math

def get_odds(n):
    lst = []
    for i in range(1, n+1):
        if i%2 == 0 or i%3 == 0 or i%5 == 0 or i%7 == 0:
            continue
        lst.append(i)
    return lst

def get_primes(n):
    if n < 2:
        lst = []
    elif n >= 2 and n < 3:
        lst = [2]
    elif n >=3 and n < 5:
        lst = [2, 3]
    elif n >=5 and n < 7:
        lst = [2, 3, 5]
    else:
        lst = [2, 3, 5, 7]
    odds = get_odds(n)[1:]
    for i in odds:
        tmp = 0
        sqt = int(math.sqrt(i)) + 1
        div_odds = get_odds(sqt)[1:]
        for j in div_odds:
            if i%j == 0:
                tmp += 1
                break
        if tmp == 0:
            lst.append(i)
    return lst

# directly get the answer
def get_res(n):
    if n < 7:
        res = 1
    else:
        res = 2
    odds = get_odds(n)[1:]
    prev = 11
    for i in odds:
        tmp = 0
        sqt = int(math.sqrt(i)) + 1
        div_odds = get_odds(sqt)[1:]
        for j in div_odds:
            if i%j == 0:
                tmp += 1
                break
        if tmp == 0:
            if i-prev == 2:
                res += 1
            prev = i
    return res

if __name__ == '__main__':
    N = 100000
    primes = get_primes(N)
    res = 0
    for i in range(len(primes)-1):
        x = primes[i+1] - primes[i]
        if x == 2:
            res += 1
    print(res)