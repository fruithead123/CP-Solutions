import sys
input = sys.stdin.readline
num = int(input())
balls = [int(i) for i in input().split()]

solved = [[-1 for i in range(num)] for i in range(num)]
for i in range(num):
    solved[i][i] = 1

def canMakeBall(start, end):
    if start>=end:
        return 1
    if solved[start][end] != -1:
        return solved[start][end]
    for i in range(start,end+1):
        for j in range(i+1,end+1):
            
            if sum(balls[start:i+1]) == sum(balls[j:min(len(balls), end+1)]):
                
                if canMakeBall(start,i) * canMakeBall(i+1,j-1) * canMakeBall(j,end) == 1:
                    solved[i][j] = 1
                    return 1
    solved[start][end] = 0
    return 0

best = max(balls)
for i in range(num):
    for j in range(i+1,num):
        if canMakeBall(i,j):
            if sum(balls[i:j+1]) > best:
                best = sum(balls[i:j+1])
print(best)
