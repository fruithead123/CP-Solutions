
n = int(input())
arr = [int(i) for i in input().split()]
best = [0 for i in range(n)]
best[0] = arr[0]
for i in range(1,n):
    best[i] = max(arr[i] + best[i-1], arr[i])
print(max(best))
