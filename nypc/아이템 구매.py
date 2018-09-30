I = map(int,raw_input().split())
P,Q = I[0], I[1]
W = int(raw_input())

n = 0
while n*P <= W:
    M = W - n*P
    if M % Q == 0:
        break
    n += 1

m = M / Q

print n,m