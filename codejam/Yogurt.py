import sys
input = sys.stdin.readline

with open('A-large.in') as fp:
    lines = fp.readlines()
    t = int(lines[0])
    for x in xrange(1,t+1):
        n, k = map(int, lines[2 * x - 1].split())
        A = map(int, lines[2 * x].split())
        A.sort()
        y = 0
        while n != 0:
            if A[0] == 0:
                del A[0]
                n -= 1
            else:
                m = min(n, k)
                for i in xrange(m):
                    del A[0]
                    n -= 1
                    y += 1
                A = map(lambda i: i - 1, A)
        print "Case #" + str(x) + ":", y