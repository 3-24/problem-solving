with open('input.txt') as fp:
    lines = fp.readlines()
    t = int(lines[0])
    count = 1
    for x in xrange (1,t+1):
        n,m,p = map(int,lines[count].split())
        count += 1
        A = [None] * n
        for i in xrange(n):
            A[i] = map(int,list(lines[count][:-1]))
            count += 1
        F = set([])
        for i in xrange(m):
            F.add(sum(map(int,list(lines[count][:-1]))))
            count += 1
        V,C = [0] * p, [0] * p
        for i in xrange(n):
            for j in xrange(p):
                V[j] += A[i][j]
        for i in xrange(p):
            V[i] = min(V[i], p-V[i])
            C[i] = abs(2*V[i] - p)
        C.sort(reverse=True)
        v = sum(V)
        s = v
        temp = 0
        while True:
            if s not in F:
                print 'Case #'+str(x)+':', s
                break
            else:
                F.remove(s)