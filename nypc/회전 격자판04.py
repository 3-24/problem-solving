N,T = map(int,raw_input().split()) # N is size of matrix, T is number of operation

INPUT = [[0 for _ in xrange(N)] for _ in xrange(N)]
for i in xrange(N):
    IN = map(int,raw_input().split())
    INPUT[i] = IN

def operation(A,N):
    B = [[0 for _ in xrange(N)] for _ in xrange(N)]
    for i in xrange(N):
        for j in xrange(N-1):
            if A[i][j] > A[i][j+1]:
                A[i][j], A[i][j+1] = A[i][j+1], A[i][j]
            B[N-1-j][i] = A[i][j]
        B[0][i] = A[i][N-1]
    return B

LOG = [INPUT]
breaked = False

for i in xrange(1,T+1):
    INPUT = operation(INPUT,N)
    LOG.append(INPUT)
    R = INPUT
    if i > 3:
        if LOG[i-4] == LOG[i]: # i, i+1, ... T <-> i-4, i-3, i-2, i-1, i-4, ...
            breaked = True
            break

if breaked:
    if (T-i) % 4 == 0:
        R = LOG[i-4]
    elif (T-i) % 4 == 1:
        R = LOG[i-3]
    elif (T-i) % 4 == 2:
        R = LOG[i-2]
    else:
        R = LOG[i-1]

for i in xrange(N):
    print " ".join(map(str,R[i]))