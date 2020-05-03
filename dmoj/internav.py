import sys
from collections import deque
input = sys.stdin.readline

m = int(input())
n = int(input())
start=[]
grid=[[0 for i in range(m)] for i in range(n)]
for i in range(n):
    row = list(input())
    for j in range(m):
        grid[i][j] = row[j]
        if grid[i][j] == '1':
            start = [i,j]
            
grid[start[0]][start[1]] = '#'
arrived = []
check = deque()
check.append([start[0]+1, start[1]])
check.append([start[0], start[1]+1])
check.append([start[0]-1, start[1]])
check.append([start[0], start[1]-1])
while len(check)>0:
    c = check.popleft()
    f,s = c[0],c[1]
    if f>-1 and s>-1 and f<n and s<m and grid[f][s] != '#':
        if grid[f][s] in '123456789':
            arrived.append(grid[f][s])
        check.append([f+1,s])
        check.append([f,s+1])
        check.append([f-1,s])
        check.append([f,s-1])
        grid[f][s] = '#'
arrived.sort()
print(1,end='')
for i in arrived:
    print(" "+i,end='')
