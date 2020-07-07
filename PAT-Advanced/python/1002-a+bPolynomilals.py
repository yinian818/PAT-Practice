listA = input().split()
listB = input().split()

def toDict(strList):
    retDict = {}
    n = int(strList[0])
    for i in range(1, n+1):
        # k = int(strList[2*i-1])
        # v = float(strList[2*i])
        retDict[int(strList[2*i-1])] = float(strList[2*i])
    return retDict

dictA = toDict(listA)
dictB = toDict(listB)

keys = sorted(set(list(dictA.keys())+list(dictB.keys())), reverse=True)

n = 0
result = ''
for k in keys:
    v = round(dictA.get(k, 0) + dictB.get(k, 0), 1)
    if v != 0:  #这一步非常重要！！！
        n += 1
        result = result + ' ' + str(k) + ' ' + str(v)

print(str(n)+result, end='')