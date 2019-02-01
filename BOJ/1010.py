def factorial(n):
    prod = 1
    for i in range (1,n+1):
        prod = prod * i
    return prod

def comb(r,n):
    num = factorial(n) / (factorial(n-r) * factorial(r))
    return num

T = int(raw_input())
for i in range (T):
    A = map(int,raw_input().split())
    print comb(A[0],A[1])