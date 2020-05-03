#import numpy as np
import math

def m(A, B):
    rowsA = len(A)
    colsA = len(A[0])
    rowsB = len(B)
    colsB = len(B[0])

    if colsA != rowsB:
      print ("Dimension error")
      return

    C = [[0 for row in range(colsB)] for col in range(rowsA)]
    for i in range(rowsA):
        for j in range(colsB):
            for k in range(colsA):
                C[i][j] += A[i][k] * B[k][j]
    return C
for i in range(int(input())):
    x,y,z,rx,ry,rz,theta = map(float,input().split())
    point = [[x,y,z,1]]
    L = (rx*rx + ry*ry + rz*rz)**0.5
    V = (ry*ry + rz*rz)**0.5
    if V == 0:
        V = 0.0001
    rotX = [[1,0,0,0],[0,rz/V,-ry/V,0],[0,ry/V,rz/V,0],[0,0,0,1]]
    rotY = [[V/L,0,-rx/L,0],[0,1,0,0],[rx/L,0,V/L,0],[0,0,0,1]]
    rotZ = [[math.cos(theta), -math.sin(theta),0,0],[math.sin(theta),math.cos(theta),0,0],[0,0,1,0],[0,0,0,1]]
    rotYInv = [[V/L,0,rx/L,0],[0,1,0,0],[-rx/L,0,V/L,0],[0,0,0,1]]
    rotXInv = [[1,0,0,0],[0,rz/V,ry/V,0],[0,-ry/V,rz/V,0],[0,0,0,1]]
    transform = m(m(m(m(rotXInv,rotYInv),rotZ),rotY),rotX)
    a = m(point,transform)
    print(a[0][0], a[0][2],a[0][1])

