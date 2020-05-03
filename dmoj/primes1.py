def primes3(n):
    a = [i for i in range(n)]
    for i in range(2,int(n**0.5)):
        if a[i]!=0:
            for j in range(i*i,n,i):
                a[j]=0
    return [i for i in a if i!=0 and i!=1]
#print(len(primes3(10000000)))

#set([i for i in range(n)]) - set([a*b for a in range(2,int(n**0.5)) for


