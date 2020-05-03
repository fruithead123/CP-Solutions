import sys
input = sys.stdin.readline
N = int(input())
sheep = [[float(input()), float(input())] for i in range(N)]
eaten = set([])
i=0.0
while i<=1000.0:
    least = 100000**2
    closest=[]
    for j in sheep:
        if (j[0]-i)**2 + j[1]**2 <= least:
            if (j[0]-i)**2 + j[1]**2 < least:
                least = (j[0]-i)**2 + j[1]**2
                closest=[]
            closest.append(j)
    for s in closest:
        eaten.add((s[0],s[1]))
    i+=0.1
    
for (i,j) in eaten:
    print("The sheep at (%.2f, %.2f) might be eaten."%(i,j))
