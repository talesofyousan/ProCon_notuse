"""
HOGEHOGE

H, W, N = [int(i) for i in input().split()]
print(type(N), H)
print(type(W), W)
print(type(N), N)
"""
A = '.'
S = 'S'
X = 'X'

INF = 1000000

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
    F = open('./input.txt', 'r')
    line = F.readline()
    items = line.split(' ')
    H = int(items[0])
    W = int(items[1])
    N = int(items[2])

    row = []
    table = []

    for i in range(H):
        line = F.readline()
        for j in range(W):
            if line[j] == '.':
                row.append(A)
            elif line[j] == 'S':
                row.append(S)
            elif line[j] == 'X':
                row.append(X)
            else:
                row.append(int(line[j]))
        table.append(row)
        row = []
    return table, H, W, N


def SolveMaze(Table, start, goal, H, W):

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
            nextcell = cell + [DX[i], DY[i]]
            if nextcell[0] >= 0 and nextcell[0] <= H - 1 and nextcell[1] >= 0 and nextcell[1] <= W - 1:
                if cost[nextcell[0]][nextcell[1]] == INF and table[nextcell[0]][nextcell[1]] != X:
                    cost[nextcell[0]][nextcell[1]] = cost[cell[0]][cell[1]] + 1

    return cost[goal[0]][goal[1]]


table, h, w, n = getTHWN()

print(h, w, n)

for i in table:
    for j in i:
        print(j, end='')
    print()

ans = SolveMaze(table, [0, 0], [2, 2], h, w)

print(ans)