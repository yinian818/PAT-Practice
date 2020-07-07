n = int(input())


def judge(s):
    if set(s) != {'P', 'A', 'T'} or s.count('P')*s.count('T') != 1:
        return 'No'

    p = s.index('P')
    t = s.index('T')

    x = p
    y = t - p - 1
    z = len(s) - t - 1
    if z != x*y:
        return 'No'
    return 'Yes'


A = []
for i in range(n):
    s = input()
    A.append(judge(s))

for m in A:
    print(m)
