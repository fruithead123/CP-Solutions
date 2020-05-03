def binomial(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in range(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0
choose=[7,31,239,50441,5889239,6698491,9890297,9954991,9950021,9950879]
lim=[4,21,168,35605,4157109,4728346,6981386,7027052,7023544,7024149]
for i in range(10):
    ans=0
    for j in range(lim[i]+1):
        ans += (binomial(choose[i],j))%(choose[i]**2)
    print(ans%(choose[i]**2))
