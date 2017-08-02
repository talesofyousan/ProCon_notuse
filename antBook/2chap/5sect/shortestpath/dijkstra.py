import heapq

INF = 1000000000000

class edge:
    def __init__(self,f,t,cost):
        self.f = f
        self.t = t
        self.cost = cost

    def getList(self):
        return [self.f,self.t,self.cost]

buff = input().rstrip().split(' ')
E = int(buff[0])
V = int(buff[1])
Graph = [[] for i in range(V)]
for i in range(E):
    s = input().rstrip().split(' ')
    Graph[int(s[0])].append(edge(int(s[0]),int(s[1]),int(s[2])))

s = 0
d = [INF for i in range(V)]
d[s] = 0
que = []
heapq.heappush(que,[0,s])

while(len(que) != 0):
    p = heapq.heappop(que)
    v = p[1]

    if d[v] < p[0]:
        continue

    for i in range(len(Graph[v])):
        e = Graph[v][i]
        if(d[e.t] > d[v] + e.cost):
            d[e.t] = d[v] + e.cost
            heapq.heappush(que,[d[e.t],e.t])

print("--------------")
for i in range(V):
    for j in range(len(Graph[i])):
        print(Graph[i][j].getList())
print("--------------")

for i in range(len(d)):
    print(d[i])