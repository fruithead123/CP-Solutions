import sys
input = sys.stdin.readline
n=int(input())
best = 1e+10
nums = list(map(int,input().split()))
nums.sort()
for j in range(1,n):
    best = min(best,abs(nums[j]-nums[j-1]))
print(best)
    

