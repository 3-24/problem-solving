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

LOG = [INPUT, None, None, None]
breaked = False

for i in xrange(1,T+1):
    INPUT = operation(INPUT,N)
    R = INPUT
    if LOG[i % 4] == INPUT: # i i+1 i+2, ... , T : i % 4, i % 4 + 1, i % 4 + 2, i % 4 +3 ...
        breaked = True
        break
    LOG[i % 4] = INPUT

if breaked:
    if (T-i) % 4 == 0:
        R = LOG[i%4]
    elif (T-i) % 4 == 1:
        R = LOG[(i + 1)%4]
    elif (T-i) % 4 == 2:
        R = LOG[(i+2)%4]
    else:
        R = LOG[(i+3)%4]

for i in xrange(N):
    print " ".join(map(str,R[i]))