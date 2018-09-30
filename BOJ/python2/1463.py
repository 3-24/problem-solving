def min_operation(X):
    R = [0,0]
    for i in range(2,X+1):
        r1, r2, r3 = i+1, i+1, i+1
        if i % 3 == 0:
            r1 = R[i/3]+1
        if i % 2 == 0:
            r2 = R[i/2]+1
        r3 = R[i-1]+1
        R.append(min(r1, r2, r3))
    return R[X]

X = int(raw_input())
print min_operation(X)