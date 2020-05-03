
def isPrime(n):
    if n==1 or n==-1:
        return "not"
    else:
        for i in range(1,int(abs(n)**0.5)+1):
            if n%i == 0 and i!=1:
                return "not"          
    return "prime"
print(isPrime(int(input())))
