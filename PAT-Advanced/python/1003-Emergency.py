import math

global minDis, s_road, most_team, cityMap, cityTeams, passed, C2

N, M, C1, C2 = [int(i) for i in input().split()]
teamList = [int(i) for i in input().split()]


def generateMap(n, m):
    cityMap = [[0 for i in range(n)] for j in range(n)]
    for i in range(m):
        x, y, r = [int(t) for t in input().split()]
        # print(x, y, r)
        cityMap[x][y] = r
        cityMap[y][x] = r
        if i < N:
            cityMap[i][i] = 0
    return cityMap


minDis = math.inf
s_road = 0
most_team = 0
cityMap = generateMap(N, M)
passed = [0 for i in range(N)]
passed[C1] = 1


def deepFirstSearch(start, distance, teams):
    global minDis, s_road, most_team, cityMap, teamList, passed, C2
    # print(distance, s_road, teams)
    if distance > minDis:
        return
    if start == C2:
        # print("###")
        if distance < minDis:
            minDis = distance
            s_road = 1
            most_team = teams
            # print("<<<<<<<")
        elif distance == minDis:
            s_road += 1
            most_team = teams if teams > most_team else most_team
            # print("==========")
        teams -= teamList[start]
        return
    # 图的深度优先搜索
    # 也可以使用非递归的方式，
    # 但是非递归方式需要使用更多的代码来记录各节点值
    # 实现起来会很复杂
    for j in range(N):
        if cityMap[start][j] != 0 and passed[j] == 0:
            passed[j] = 1
            distance += cityMap[start][j]
            teams += teamList[j]
            deepFirstSearch(j, distance, teams)
            # 当前节点扫描完成之后，要把加到diatance和teams上的值减去
            # 或者也可以在传参的时候加，不需要改变变量值，可以省掉四行代码
            distance -= cityMap[start][j]
            teams -= teamList[j]
            passed[j] = 0
    return


deepFirstSearch(C1, 0, teamList[C1])
print("%s %s" % (str(s_road), str(most_team)), end="")


"""
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
"""
