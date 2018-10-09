import sys
input = sys.stdin.readline

n,m = map(int,input().split())
A = [0 for _ in xrange(n)] + [int(input()) for _ in xrange(n)] # 20
B = list(A)
for i in xrange (n-1,0,-1):
    A[i], B[i] = min(A[i << 1], A[i << 1 | 1]), max(B[i << 1], B[i << 1 | 1])

for _ in xrange(m):
    a,b = map(lambda x:int(x)+n-1, input().split())
    if a > b:
        print 0,0
    r1 = set([])
    r2 = set([])
    while a <= b:
        if a & 1:
            r1.add(A[a])
            r2.add(B[a])
        if not b & 1:
            r1.add(A[b])
            r2.add(B[b])
        a = a + 1 >> 1
        b = b - 1 >> 1
    print min(r1), max(r2)
