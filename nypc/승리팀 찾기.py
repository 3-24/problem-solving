T = int(raw_input())

for _ in xrange(T):
    if raw_input() == 'item':
        flag = -1
        t = 600
        for i in xrange(8):
            I = raw_input().split()
            time = map(float, I[1].split(':'))
            nt = time[0]*60 + time[1]
            if t > nt:
                t = nt
                flag = I[0]
        print flag
    else:
        S = []
        mint = 600
        for i in xrange(8):
            I = raw_input().split()
            time = map(float,I[1].split(':'))
            nt = time[0] * 60 + time[1]
            if mint > nt:
                mint = nt
            S.append((I[0],nt))
        S.sort(key=lambda x: x[1])
        r,b = 0,0
        point = [10,8,6,5,4,3,2,1]
        for i in xrange(8):
            if S[i][1] < mint + 10:
                if S[i][0] == 'red':
                    r += point[i]
                else:
                    b += point[i]
        if r > b:
            print 'red'
        elif r < b:
            print 'blue'
        else:
            print S[0][0]