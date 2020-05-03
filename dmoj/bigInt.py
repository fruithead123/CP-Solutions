'''
import sys
input = sys.stdin.readline

n = int(input())
s = input().strip()
tot=0
cur=0
for i in s:
    if i == '-':
        cur = int(cur/10)
        tot += cur
    else:
        cur = 10*cur + int(i)
        tot += cur
print(tot)
'''

    
