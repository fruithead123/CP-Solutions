import sys
input = sys.stdin.readline

k,p,x = map(int,input().split())
exactMin = 2*(k*p*x)**0.5
exactM = (k*p/x)**0.5
if(int(exactM) == 0):
    a = 1000000000000
else:
    a=x*int(exactM) + k*p/int(exactM)
b = x*(int(exactM)+1) + k*p/(int(exactM)+1)
ans = min(a,b)
print("%.3f"%ans)
