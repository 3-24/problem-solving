n = int(raw_input())
S = []
i = 1
for _ in xrange (n):
    print S
    x = int(raw_input())
    if x not in S:
        while True:
            S.append(i)
            print '+'
            i += 1
            if x in S:
                S.pop()
                print '-'
                break
    else:
        if S[-1] != x:
            print 'NO'
            break
        else:
            S.pop()
            print '-'