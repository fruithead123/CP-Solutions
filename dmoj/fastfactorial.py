def largestPower(n,p):
    res = 0
    while n>0:
        n = n//p
        res += n
    return res

def modPower(base,exp,mod):
    ans = 1
    base = base%mod

    while exp>0:
        if exp%2 == 1:
            ans = (ans*base) % mod

        exp = exp//2
        base = (base*base) % mod
    return ans

def factP(n,p):
    if n>=p:
        return 0
    res = 1
    primes = [1 for i in range(n+1)]
    for i in range(2,int(n**0.5)+1):
        if primes[i] == 1:
            for j in range(2*i, n+1, i):
                primes[j] = 0

    for i in range(2,n+1):
        if primes[i] == 1:
            k = largestPower(n,i)
            res = (res*modPower(i,k,p)) % p
    return res
for i in range(int(input())):
    print(factP(int(input()), 2**32-5))
