import time
n = int(input())

# t1 = time.time()


def Callatz(n):
    if n == 1:
        return 0
    elif n % 2 == 0:
        return Callatz(n//2) + 1
    else:
        return Callatz((3*n+1)//2) + 1


# t2 = time.time()

print(Callatz(n))
# print(t2-t1)
