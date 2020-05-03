import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000)
def isMonkey(word):
    if word == 'A':
        return True
    elif word == "":
        return False
    else:
        good = False
        if 'N' in word:
            indicies = [i for i,x in enumerate(word) if x == 'N']
            for pos in indicies:
                if pos != 0 and pos!= len(word)-1 and isMonkey(word[:pos]) and isMonkey(word[pos+1:]):
                    good = True
        if word[0] == 'B' and word[-1] == 'S':
            if isMonkey(word[1:-1]):
                good = True
        return good
while True:
    word = input().strip()
    if word == 'X':
        break
    else:
        if isMonkey(word):
            print("YES")
        else:
            print("NO")
