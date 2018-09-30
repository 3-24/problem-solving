N = int(raw_input())
X,Y = [], []
for _ in xrange(N):
    IN = map(int, raw_input().split())
    X.append(IN[0])
    Y.append(IN[1])

fN = float(N)

print sum(X)/fN, sum(Y)/fN