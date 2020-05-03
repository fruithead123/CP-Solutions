import sys
input = sys.stdin.readline
money = int(input())
num = int(input())

vals = [0 for i in range(num)]
best = [10000 for i in range(money+1)]
best[0] = 0
for i in range(num):
    vals[i] = int(input())
for i in range(money):
    for j in vals:
        if i+j<=money and best[i+j] > best[i]+1:
            best[i+j] = best[i] + 1
print(best[money])
