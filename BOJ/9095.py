def main(n):
    T = []
    for i in range (n+1):
        if i == 0:
            T.append(0)
        elif i == 1:
            T.append(1)
        elif i == 2:
            T.append(2) #1+1, 2
        elif i == 3:
            T.append(4) #1+1+1,1+2,2+1,3
        else:
            T.append(T[i-1]+T[i-2]+T[i-3])

    return T[n]

k = int(raw_input())
for i in range (k):
    t = int(raw_input())
    print main(t)