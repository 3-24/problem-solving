n = int(raw_input())
P = map(int, raw_input().split())
P = [0]+P
p = len(P)

S = []
for i in range (1+p):
    if i == 0:
        S.append(0)
    else:
        const = 0
        for j in range (i): #0,1,...,i-1
            if const < S[j] + P[i-j]:
                const = S[j] + P[i-j]
        S.append(const)
print S[-1]