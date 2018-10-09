def find(endindex,stemina):
    u,e = L[endindex]
    if endindex == 0:
        if u > stemina:
            return [0,0,[]]
        else:
            return [e,1,[endindex + 1]]
    else:
        F1 = [-1,0,[]]
        if u <= stemina:
            F1 = find(endindex-1, stemina-u)
            F1[0] += e
            F1[1] += 1
            F1[2].append(endindex + 1)
        F2 = find(endindex-1, stemina)

        if F1[0] > F2[0]:
            return F1
        else:
            return F2



s = int(raw_input())
n = int(raw_input())
L = [0]*n

for i in xrange(0,n):
    L[i] = map(int,raw_input().split())

F = find(n-1,s)
print F[0]
print F[1]
print " ".join(map(str, F[2]))