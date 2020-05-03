import sys
input = sys.stdin.readline

n = [int(input()) for i in range(int(input()))]
m = max(n)
s = sum(n)
if s < 2*m:
    print(s-m)
else:
    print(s//2)
