import sys
input = sys.stdin.readline

for i in range(int(input())):
    s = input()
    count = 0
    for l in range(len(s)):
        for r in range(l,len(s)):
            
            if s.find(s[l:r]) == l:
                count += 1
    print(count)
