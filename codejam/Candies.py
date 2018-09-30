import sys
input = sys.stdin.readline

n = int(input())
for k in xrange(n):
    N, O, D = map(int, input().split())
    X1, X2, A, B, C, M, L = map(int, input().split())
    S = [X1, X2]
    stot = -sys.maxint
    for i in xrange(n):
        j = i

    if stot == -sys.maxint:
        value = 'IMPOSSIBLE'
    else:
        value = str(stot)
    print 'Case #'+str(k+1)+': '+ value