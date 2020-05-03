import sys
input = sys.stdin.readline

def loosePos(a,b,c,d):
    if a<0 or b<0 or c<0 or d<0:
        return False
    return not winPos[a][b][c][d]
moves = [[2,1,0,2],
         [1,1,1,1],
         [0,0,2,1],
         [0,3,0,0],
         [1,0,0,1]]

winPos = [[[[False for i in range(31)]for j in range(31)]for k in range(31)]for l in range(31)]
for i in range(31):
    for j in range(31):
        for k in range(31):
            for l in range(31):
                for m in range(5):
                    if loosePos(i-moves[m][0], j-moves[m][1], k-moves[m][2], l-moves[m][3]):
                        winPos[i][j][k][l] = True
n = int(input())
for i in range(n):
    a,b,c,d = map(int, input().split())
    if winPos[a][b][c][d]:
        print("Patrick")
    else:
        print("Roland")
