import sys,math
input = sys.stdin.readline
N = 10**9+7
memo=dict()
memo[0] = 1
memo[1] = 1
def F(n):
    return fib(n-1)
def fib(n):
    if n in memo:
        return memo[n]
    k = n // 2
    if n%2 == 0:
        memo[n] = fib(k)*fib(k) + fib(k-1)*fib(k-1)
        return memo[n]
    else:
        memo[n] = fib(k)*fib(k+1) + fib(k-1)*fib(k)
        return memo[n]
        
print(F(int(input())) % N)
