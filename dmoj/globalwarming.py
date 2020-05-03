import sys
input =sys.stdin.readline

while True:
    vals = list(input().split())
    if vals == ['0']:
        break
    else:
        n = int(vals.pop(0))
        if n == 1:
            print(0)
        else:
            temps = [int(vals[i+1]) - int(vals[i]) for i in range(n-1)]
            f=False
            for i in range(1,n):
                good = True
                for j in range(n-i-1):
                    if temps[j] != temps[j+i]:
                        good = False
                if good:
                    print(i)
                    f = True
                    break
            if not f:
                print(n)
