import sys
input = sys.stdin.readline

n,m = map(int,input().split())
A = [0 for _ in xrange(n)] + [int(input()) for _ in xrange(n)]

for i in xrange(n-1,0,-1):
    A[i] = min(A[i << 1], A[i << 1 | 1])

for _ in xrange(m):
    a,b = map(lambda x: int(x) + n-1,input().split())
    if a > b:
        print 0
    r = set([])
    while a <= b:
        if a & 1:
            r.add(A[a])
        if not b & 1:
            r.add(A[b])
        a = a + 1 >> 1
        b = b - 1 >> 1
    print min(r)