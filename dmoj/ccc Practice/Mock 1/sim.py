import sys
import math
input = sys.stdin.readline
#n=int(input())


def sim1(n):
    a=0.5*( -(2*n**2 + 6*n +1)**0.5 +2*n-1) +1
    if int(a) == a:
        return math.ceil(a+1)
    else:
        return math.ceil(a)
def sim2(n):
    threshold = n*(n-1)/2
    k=1
    count=0
    vals=0
    while k<n:
        l=k+1
        vals=k
        while l<=n:
            count+=1
            l+=1
            if 2*count >= threshold:
                return vals
        k+=1
bad=[]
for i in range(2,500):
    if sim1(i) == sim2(i):
        print(i, True)
    else:
        print(i,False,sim1(i), sim2(i))
        bad.append((i,sim1(i), sim2(i)))
print(bad)
