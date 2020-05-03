import sys
input = sys.stdin.readline

dim = int(input())

reduced = False
valid = set()
order=[]
for i in range(0,min(10,dim)):
    valid.add(str(i))
    order.append(str(i))
if dim>10:
    for i in range(0,dim-10):
        valid.add(chr(65+i))
        order.append(chr(65+i))
square = [list(input().strip()) for i in range(dim)]
bad = False
for i in range(dim):
    if not valid - set(square[i]) == set():
        bad = True
        
    a=[square[j][i] for j in range(dim)]
    if not valid - set(a) == set():

        bad = True

if square[0] == order and [square[j][0] for j in range(dim)] == order:
    reduced = True
if bad:
    print("No")
else:
    if reduced:
        print("Reduced")
    else:
        print("Latin")
        
