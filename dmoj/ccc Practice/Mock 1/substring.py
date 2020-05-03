import sys
input = sys.stdin.readline

string = input()
found = False
for i in range(2,101,2):
    for j in range(0,len(string)-i+1):
        if not found:
            chunk = string[j:j+i]
            if chunk == chunk[::-1]:
                found = True
if found:
    print("Even")
else:
    print("Odd")
