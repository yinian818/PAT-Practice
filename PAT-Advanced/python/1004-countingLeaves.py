# 根据家族族谱，输出每一代中，没有孩子的成员数量
# 树的层次遍历

N, M = [int(i) for i in input().split()]
memMap = [[0 for i in range(N)] for i in range(N)]

for i in range(M):
    childList = [int(i) - 1 for i in input().split()]
    x = childList[0]
    for y in childList[2:]:
        memMap[x][y] = 1


father = [0]
children = []
result = []
layerNoChil = 0
while father != []:
    i = father.pop()
    noChil = 1
    for j in range(N):
        if memMap[i][j] != 0:
            children.append(j)
            noChil = 0
    layerNoChil += noChil
    if father == []:
        father = children
        children = []
        result.append(str(layerNoChil))
        layerNoChil = 0

print(" ".join(result), end="")

"""
6 3
1 2 3 5
2 1 4
3 1 6

"""
