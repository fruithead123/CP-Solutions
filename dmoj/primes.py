print(*([2]+[str(i) + ('*' if (2**(i+2)%(i+2)==2 or 2**(i-2)%(i-2)==2) else '') for i in range(1, int(input())) if 2**i%i==2]), sep='\n')
