import sys
input = sys.stdin.readline
dim = int(input())
start = [float(i) for i in input().split()]
end = [float(i) for i in input().split()]

ans = 0
for i in range(dim):
    ans += ((end[i] - start[i])**2)
print(ans**0.5)
