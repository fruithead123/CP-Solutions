import sys
input = sys.stdin.readline
for i in range(int(input())):
    row  = int(input())
    cols  = int(input())
    maze = [] 
    for j in range(row):
        maze.append(input())
    if maze[row-1][cols-1] == "*":
        print(-1)
        continue
    check = [(0,0,1)] 
    visited = []
    moves = {
             '+':[(1,0),(-1,0),(0,1),(0,-1)],
             '|':[(0,1),(0,-1)], 
             '-':[(1,0),(-1,0)]  
            }
    while True:
        if len(check) == 0: 
            print (-1)
            break
        x,y,intersections = check.pop()
        if (x == -1 or x == cols) or (y == -1 or y == row):
            continue
        if maze[y][x] == '*':
            continue
        if (x,y) in visited:
            continue
        if (x,y) == (cols-1,row-1): 
            print (intersections)
            break
        visited.append((x,y))
        symbol = maze[y][x]
        for (dx,dy) in moves[symbol]:
            check.append((x+dx, y+dy, intersections+1))
           
    
