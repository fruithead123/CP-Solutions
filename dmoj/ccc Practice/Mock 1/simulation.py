def sim(n):
    thresh = n*(n-1)//2
    k=1
    count = 0
    nums=[]
    while k<n:
        l=k+1
        nums.append(k)
        while l<=n:
            count+=1
            l+=1
            if 2*count >= thresh:
                return nums
        k+=1

def sim2(n):
    k=1
    count=0
    for i in range(k,n+1):
        print(i)
        for j in range(i,n+1):
            count+=1
            if count == n(n-1)//4:
                return -1
               
for i in range(40):
    print("%d. %s"%(i, sim(i)))
