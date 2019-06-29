# coding: utf-8


# 不要尝试直接找出结果，endindex 是肯定确定的，
# 所以可以根据 endindex 和 maxsum 确定 startindex

# 1.0 直接找结果
# 2.0 test2-2
# 3.0 test2-3 优化上一版
# 最终版 test2

def get_res(nums):
    n = len(nums.split())
    # n = input()
    # nums = input()
    n = int(n)
    add, maxadd, tmpadd = 0, 0, 0
    m, t= 0, 0
    lst = [int(i) for i in nums.split()]
    for i, value in enumerate(lst):
        if value < 0:
            m += 1
        if value == 0:
            t += 1
        add += value
        if add > maxadd:
            maxadd = add
            end = value
            endindex = i
        elif add < maxadd and add < 0:
            add = 0
    if m == n:
        res = (0, lst[0], lst[-1])
    elif t > 0 and m+t == n:
        res = (0, 0, 0)
    else:
        j = 0
        startindex = n - endindex - 1
        for j, value in enumerate(lst[::-1]):
            if j < startindex:
                continue
            tmpadd += value
            if tmpadd == maxadd:
                startindex = j
        startindex = n - startindex - 1
        res = (maxadd, lst[startindex], end)
    return res


if __name__ == '__main__':

    nums = "0 0 0 0 1 -1 2 0 0 0"
    res = get_res(nums)
    assert res[0] == 2
    assert res[1] == 0
    assert res[2] == 2

    nums = "0 0 0 0 1 2"
    res = get_res(nums)
    assert res[0] == 3
    assert res[1] == 0
    assert res[2] == 2
    

    nums = "-10 1 2 3 4 -5 -23 3 7 -21"
    res = get_res(nums)
    print(res)
    print(res[0], res[1], res[2])
    assert res[0] == 10
    assert res[1] == 1
    assert res[2] == 4
    
    nums = "2 5 -8 7 3"
    res = get_res(nums)
    assert res[0] == 10
    assert res[1] == 7
    assert res[2] == 3
    
    nums = "2 5 -11 -2 5 2"
    res = get_res(nums)
    assert res[0] == 7
    assert res[1] == 2
    assert res[2] == 5
    
    nums = "-1 0 0"
    res = get_res(nums)
    assert res[0] == 0
    assert res[1] == 0
    assert res[2] == 0
    
    nums = "1 -1 0"
    res = get_res(nums)
    assert res[0] == 1
    assert res[1] == 1
    assert res[2] == 1
    
    nums = "-1 -3"
    res = get_res(nums)
    assert res[0] == 0
    assert res[1] == -1
    assert res[2] == -3
    
    nums = "1 -2 3 1 0"
    res = get_res(nums)
    assert res[0] == 4
    assert res[1] == 3
    assert res[2] == 1
    
    nums = "1 2 3 1 0"
    res = get_res(nums)
    assert res[0] == 7
    assert res[1] == 1
    assert res[2] == 1
    
    nums = "-1 0 0 -1"
    res = get_res(nums)
    assert res[0] == 0
    assert res[1] == 0
    assert res[2] == 0
    
    nums = "0 1 -1 2 -1 1 0 2 0 0"
    res = get_res(nums)
    assert res[0] == 4
    assert res[1] == 0
    assert res[2] == 2
    
    nums = "2 -1 1 0 2 0 0"
    res = get_res(nums)
    assert res[0] == 4
    assert res[1] == 2
    assert res[2] == 2

    nums = "0 0 0 0 -1 0 0 2 3 0"
    res = get_res(nums)
    assert res[0] == 5
    assert res[1] == 0
    assert res[2] == 3

    nums = "-3 -2 -1 0 0 0"
    res = get_res(nums)
    assert res[0] == 0
    assert res[1] == 0
    assert res[2] == 0

    nums = "0 -2 3 5 -1 2"
    res = get_res(nums)
    assert res[0] == 9
    assert res[1] == 3
    assert res[2] == 2


