N,T = map(int,raw_input().split()) # N is size of matrix, T is number of operation

INPUT = [[0 for _ in xrange(N)] for _ in xrange(N)]
for i in xrange(N):
    IN = map(int,raw_input().split())
    INPUT[i] = IN

def operation(A,N):
    for i in xrange(0,N):
        for j in xrange(0,N-1):
            if A[i][j] > A[i][j+1]:
                A[i][j], A[i][j+1] = A[i][j+1], A[i][j]

    B = [[0 for _ in xrange(N)] for _ in xrange(N)]
    C = A[:]

    for i in xrange(N):
        C[i].reverse()
        for j in xrange(N):
            B[j][i] = C[i][j]
    return B


for _ in xrange(T):
    INPUT = operation(INPUT,N)

for i in xrange(N):
    print " ".join(map(str,INPUT[i]))