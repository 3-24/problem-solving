N,k = map(int,raw_input().split())

if k > N:
    print 0
    exit()

t = k
S = [0] * (k+1)

while N <= 2 ** t -1:
    t -= 1



def factorial(n):
    prod = 1
    for i in xrange (1,n+1):
        prod = prod * i
    return prod

def comb(n,r):
    if n < r:
        return 0
    return factorial(n)/(factorial(n-r) * factorial(r))

for i in xrange (N+1,k+1):
    S[i] = comb(2**i -1, N) - S[i-1]