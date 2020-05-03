intervals,days = map(int, input().split())
jumps = [int(i) for i in input().split()]
possible=[]
for i in jumps:
    if abs(days)%i == 0:
        possible.append(abs(days)/i)


if len(possible) == 0:
    print("This is not the best time for a trip")
else:
    print(int(min(possible)))
