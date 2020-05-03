import sys
input = sys.stdin.readline
def dist(x1,y1,x2,y2):
    return ((x2-x1)**2 + (y2-y1)**2)**0.5
for i in range(int(input())):
    x1,y1,x2,y2,x3,y3 = map(int,input().split())
    a = abs(0.5*((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)))
    p = dist(x1,y1,x2,y2) + dist(x1,y1,x3,y3) + dist(x2,y2,x3,y3)
    print(a,p)
