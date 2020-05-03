import sys
input = sys.stdin.readline

n = int(input())
friends = [0 for i in range(10000)]
for i in range(n):
    x,y = map(int, input().split())
    friends[x] = y

while True:
    x,y = map(int,input().split())
    if x == 0 and y == 0:
        break
    else:
        visited = [x]
        pos = friends[x]
        count = 0
        while True:
            if pos == y:
                print("Yes " + str(count))
                break
            elif pos in visited:
                print("No")
                break
            visited.append(pos) 
            pos = friends[pos]
            count += 1
