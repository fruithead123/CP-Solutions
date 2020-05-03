import sys
input = sys.stdin.readline

for c in range(int(input())):
    r = int(input())
    c = int(input())
    maze = [list(input().strip())for i in range(r)]
    visited = []
    check=[(0,0,1)]
    best = []
    while True:
        if len(check) > 0:
            x,y,i = check.pop(0)
            if (x,y) in visited:
                continue
            #print(x,y,i)
            if x>c-1 or y>r-1 or x<0 or y<0:
                continue
            if maze[y][x] == "*":
                continue
            if x==c-1 and y == r-1:
                best.append(i)
                continue
            if maze[y][x] == "+":
                check.append((x+1,y,i+1))
                check.append((x-1,y,i+1))
                check.append((x,y+1,i+1))
                check.append((x,y-1,i+1))
            if maze[y][x] == "-":
                check.append((x+1,y,i+1))
                check.append((x-1,y,i+1))
            if maze[y][x] == "|":
                check.append((x,y+1,i+1))
                check.append((x,y-1,i+1))
            visited.append((x,y))
        else:
            if len(best) == 0:
                print(-1)
            else:
                print(min(best))
            break
        
