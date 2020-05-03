import sys
input = sys.stdin.readline
num = int(input()) + 1
while True:
    if not '0' in str(num):
        print(num)
        break
    else:
        num+=1
