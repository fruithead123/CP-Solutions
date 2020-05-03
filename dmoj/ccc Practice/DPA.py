import sys
input = sys.stdin.readline

for i in range(int(input())):
    num = int(input())
    count = 1
    for j in range(2,num):
        if num%j == 0:
            count += j
    if count == num:
        print('%d is a perfect number.'%num)
    elif count > num:
        print('%d is an abundant number.'%num)
    else:
        print('%d is a deficient number.'%num)
