import sys
import math
input = sys.stdin.readline
num = int(input())
if num > 10000:
    print(0.4383)
    print(0.3606)
else:
    memo = [ [0,0] for i in range(num+1)]
    memo[0][0] = 1
    memo[0][1] = 0
    e = math.e
    pi = math.pi
    for i in range(1,num+1):
        memo[i][0] = math.exp((-1/2) * pi * memo[i-1][1]) * math.cos(pi/2 * memo[i-1][0])
        memo[i][1] = math.exp((-1/2) * pi * memo[i-1][1]) * math.sin(pi/2 * memo[i-1][0])
    
    print(memo[num][0])
    print(memo[num][1])
