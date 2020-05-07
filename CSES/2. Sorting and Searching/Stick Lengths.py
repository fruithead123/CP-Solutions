
n = int(input())
arr = [int(i) for i in input().split()]
arr.sort()
best = [10**9 for i in range(n)]
best[0] = sum([arr[i] - arr[0] for i in range(1,n)])
for i in range(1,n):
    best[i] = best[i-1] + (arr[i] - arr[i-1]) * (2*i-n)
print(min(best))
