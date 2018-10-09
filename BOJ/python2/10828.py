n = int(raw_input())
S = []
for _ in xrange(n):
    A = raw_input().split()
    if A[0] == 'push':
        S.append(int(A[1]))
    elif A[0] == 'pop':
        if not S: print -1
        else: print S.pop()
    elif A[0] == 'size':
        print len(S)
    elif A[0] == 'empty':
        print int(len(S) == 0)
    elif A[0] == 'top':
        if not S: print -1
        else: print S[-1]
