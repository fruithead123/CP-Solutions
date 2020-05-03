import sys
input = sys.stdin.readline
calls, mins = map(int, input().split())
people = list(map(int,input().split()))
ans = 0
for i in range(mins):
    ans += max(people)
    people[people.index(max(people))] -= 1
print(ans)
