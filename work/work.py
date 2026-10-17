for i in range(1,1001):
    f = 1
    for j in range(1,i-1):
        if (10**j -1) % i == 0:
            f = 0
    if (10**(i-1) -1) % i != 0:
        f = 0
    if f:
        print(i)