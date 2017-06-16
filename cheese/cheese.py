A = '.'
S = 'S'
X = 'X'

INF = -1

DX = [1, 0, -1, 0]
DY = [0, 1, 0, -1]


class Que:
    def __init__(self):
        self.que = []

    def getFront(self):
        return self.que[0]

    def pop(self):
        del self.que[0]

    def push(self, back):
        self.que.append(back)

    def getLen(self):
        return len(self.que)


def getTHWN():

    H, W, N = [int(i) for i in input().split()]

    goals = [0 for i in range(N + 1)]

    row = []
    table = []

    for i in range(H):
        line = input()
        for j in range(W):
            if line[j] == '.':
                row.append(A)
            elif line[j] == 'S':
                goals[0] = [i, j]
                row.append(S)
            elif line[j] == 'X':
                row.append(X)
            else:
                row.append(int(line[j]))
                goals[int(line[j])] = [i, j]
        table.append(row)
        row = []
    return table, H, W, N, goals


def SolveMaze(table, start, goal, H, W):

    q = Que()

    q.push(start)

    cost = []
    for i in range(H):
        row = []
        for j in range(W):
            row.append(INF)
        cost.append(row)

    cost[start[0]][start[1]] = 0

    while q.getLen() != 0:
        cell = q.getFront()
        q.pop()

        if cell[0] == goal[0] and cell[1] == goal[1]:
            break

        for i in range(4):
            nextcell = [cell[0] + DX[i], cell[1] + DY[i]]
            if nextcell[0] >= 0 and nextcell[0] <= H - 1 and nextcell[1] >= 0 and nextcell[1] <= W - 1:
                if cost[nextcell[0]][nextcell[1]] == INF and table[nextcell[0]][nextcell[1]] != X:
                    cost[nextcell[0]][nextcell[1]] = cost[cell[0]][cell[1]] + 1
                    q.push(nextcell)

    return cost[goal[0]][goal[1]]


table, h, w, n, cheese = getTHWN()

ans = 0
for i in range(len(cheese) - 1):
    ans += SolveMaze(table, cheese[i], cheese[i + 1], h, w)

print(ans)