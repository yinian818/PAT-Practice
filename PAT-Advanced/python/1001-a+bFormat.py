a, b = [int(i) for i in input().split()]
c = a+b


def formatNum(intNum):
    s = str(intNum)
    i = len(s) % 3 if len(s) % 3 != 0 else 3
    ret = s[:i]
    while i < len(s):
        add = ',' + s[i:i+3]
        ret += add
        i += 3
    return ret

c_s = formatNum(c) if c >= 0 else '-'+formatNum(-c)

print(c_s)