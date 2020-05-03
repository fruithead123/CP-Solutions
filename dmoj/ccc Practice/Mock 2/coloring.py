import sys
from pprint import pprint
input = sys.stdin.readline

h,w = map(int,input().split())
grid = []
for i in range(h):
    layer=[]
    for j in input().strip():
        layer.append(j)
    grid.append(layer)

for i in range(h):
    for j in range(w):
        if grid[i][j] == 'B':
            for k in range(i+1):
                for l in range(j+1):
                    grid[k][l] = "B"
        elif grid[i][j] == 'R':
            for k in range(i,h):
                for l in range(j,w):
                    grid[k][l] = "R"
#pprint(grid)
empty=[]

for i in range(h):
    for j in range(w):
        if grid[i][j] == '.':
            empty.append([i,j])
#print(empty)
if len(empty) == 0:
    print(0)
else:
    groups = []
    while len(empty) > 0:
        print("NEXT")
        current=[empty.pop(0)]
        print(empty)
        for i in empty: 
            for check in current:
                if abs(check[0]-i[0]) == 1 or abs(check[1] - i[1]) == 1:
                    if i not in current:
                        current.append(i)
            empty.remove(i)
        groups.append(current)
    print(groups)
    ans = 1
    for i in groups:
        ans *= (len(i)+1)
    print(ans)
