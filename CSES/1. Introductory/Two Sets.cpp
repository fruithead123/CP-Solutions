
import sys
n = int(input())
s = n*(n+1) // 2
if s%2 == 1:
    print("NO")
else:
    snd = [0 for i in range(n+1)]
    tgt = s // 2
    c = 0
    for i in range(n, 0, -1):
        c+=1
        #print(i,tgt)
        if tgt > i:
            snd[i] = 1
            tgt -= i
        else:
            snd[tgt] = 1
            break


    sys.stdout.write("YES\n")
    sys.stdout.write("%d\n"%(n-c))
    for i in range(1,n+1):
        if snd[i] == 0:
            sys.stdout.write("%d "%(i))
    sys.stdout.write("\n")

    sys.stdout.write("%d\n"%c)
    for i in range(1,n+1):
        if snd[i] == 1:
            sys.stdout.write("%d "%(i))
    sys.stdout.write("\n")


