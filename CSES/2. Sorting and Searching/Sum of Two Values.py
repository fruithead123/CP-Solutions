
n,x = map(int, input().split())
d={}
arr = [int(i) for i in input().split()]
for i in range(n):
    d[x-arr[i]] = i
f=False
for i in range(n):
    if arr[i] in d and d[arr[i]] != i:
        print("%d %d"%(i+1, 1+d[arr[i]]))
        f = True
        break
if not f:
    print("IMPOSSIBLE")

