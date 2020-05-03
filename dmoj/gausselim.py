import sys
from pprint import pprint
input = sys.stdin.readline

def solve(r,c):
    if r<0 or c<0:
        pass
    elif dp[r][c] != -1:
        return dp[r][c]
    elif solve(r-1,c) and solve(r,c-1):
        dp[r][c] = False
        return False
    else:
        dp[r][c] = True
        return True

rows = int(input())
cols = int(input())
dp = [[-1 for i in range(rows)] for j in range(cols)]
dp[0][0] = True

print(solve(cols-1, rows-1))
pprint(dp)
