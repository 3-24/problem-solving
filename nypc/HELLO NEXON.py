L = map(int,raw_input().split())
N,M = L[0], L[1]
c = 0
for _ in xrange(N):
    P = raw_input().split()
    for i in xrange(M):
        if P[i] == 'NEXON':
            c += 1
print c