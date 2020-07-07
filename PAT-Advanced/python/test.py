def deepFirstSearch(cityMap, start, end, cityTeams):
    shortest, roads = math.inf, 0
    mostTeam = cityTeams[start]
    n = len(cityTeams)

    i = start
    distance = 0
    team = cityTeams[i]
    cityPassed = [start]
    trash = []
    p,q,r = 0, 0, 0
    for j in range(n):
        if distance > shortest
        if i == end:
            p += 1
            # 如果这是当前最短路径，那么就必须要走这一条
            if distance < shortest:
                shortest = distance
                roads = 1
                mostTeam = team
            # 如果和已有最短路径距离相同，要比较搜救队的数量
            elif distance == shortest:
                print(shortestRoads)
                roads += 1
                if team > mostTeam:
                    mostTeam = team
            k = cityPassed.pop()
            i = cityPassed[-1]
            j = k + 1
            team -= cityTeams[k]
            distance -= cityMap[i][k]
        elif cityMap[i][j] != 0 and j not in cityPassed and j not in trash:
            q+=1
            distance += cityMap[i][j]
            cityPassed.append(j)
            team += cityTeams[j]
            i, j = j, 0
        if j == n - 1:
            r+=1
            if cityPassed[-1] == start:
                break
            k = cityPassed.pop()
            trash.append(k)
            i = cityPassed[-1]
            j = k + 1
            team -= cityTeams[k]
            distance -= cityMap[i][k]
    print(p,q,r)
    return roads, mostTeam

teamMap = generateMap(N, M)
roads, teams = deepFirstSearch(teamMap, C1, C2, teamList)
print(str(roads), str(teams), end='')