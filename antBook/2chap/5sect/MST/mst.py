import numpy as np
import heapq

MAX = 10000000000

FLAG1 = 0
FLAG2 = 1
FLAG3 = 2

inputlines = int(input())
graph = np.zeros((inputlines,inputlines))

#print(graph)

for i in range(inputlines):
    buff = input().rstrip().split(' ')
    for j in range(inputlines):
        graph[i][j] = int(buff[j])


#print(graph)

flags = np.zeros(inputlines)
d = np.ones(inputlines)*MAX
p = np.ones(inputlines)
d[0] = 0
p[0] = -1

que = []

v = inputlines

for i in range(v):
    for j in range(i,v):
        if graph[i][j] != -1:
            heapq.heappush(que,[graph[i][j],i,j])

print (que)

while(True):
    mincost = MAX
    for i in range(v):
        if flags[i] != FLAG3 and mincost > d[i]:
            mincost = d[i]
            u = i
    
    if mincost == MAX:
        break

    flags[u] = FLAG3

    for i in range(v):
        if flags[i] != FLAG3 and graph[i][u] != -1:
            if d[i] > graph[i][u]:
                d[i] = graph[i][u]
                p[i] = u
                flags[i] = FLAG2

print(p)
print("-------------------")
print(d)