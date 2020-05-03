import sys
input = sys.stdin.readline

print('guess 0')
n = int(input())
if n == 0:
    print('answer 0')
else:
    p = [-n,n]
    print('guess 25')
    m = int(input())
    p2 = [25-m, 25+m]
    for i in p:
        for j in p2:
            if i == j:
                print('answer ' + str(i))
                break
