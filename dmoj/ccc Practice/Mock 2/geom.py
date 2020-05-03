import sys
input = sys.stdin.readline
try:
    a = 0
    s=[]
    for i in range(3):
        l,w = map(int, input().split())
        a += l*w
        s.append([l,w])
        
    if not a**0.5 == int(a**0.5):
        print("NO")
    else:
        side = a**0.5
        req = 0
        found = False
        for i in s:
            if side in i:
                found = True
                req = side - i[(i.index(side)+1)%2]
                s.remove(i)
        if not found:
            print("NO")
        else:
            a1=(s[0].index(req)+1)%2
            a2=(s[1].index(req)+1)%2
            if s[0][a1] + s[1][a2] == side:
                print("YES")
            else:
                print("NO")
except:
    print("NO")
        
