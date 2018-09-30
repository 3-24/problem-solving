def wine_point1(li):
    sum = 0
    for i in li:
        sum += i
    R=[]
    l = len(li)
    for i in range (l):
        if i == 0:
            R.append([0,0,li[i]])
        elif i == 1:
            R.append([0,li[i-1],li[i]])
        elif i == 2:
            R.append([li[i-2],li[i-1],li[i]])
        else:
            r1 = min(R[i-3])+li[i-2]
            r2 = min(R[i-3][1:3])+li[i-1]
            r3 = R[i-3][2]+li[i]
            R.append([r1,r2,r3])
    return sum - min(R[l-1])

def wine_point2(A):
    n = int(raw_input())
    if n <= 2:
        return sum(A)
    else:
        P = [0] * n
        Q = [0] * n
        P[0], P[1], Q[0], Q[1] = A[0], A[1], A[0], A[0] + A[1]
        for i in range(2, n):
            P[i] = max(P[i - 2], Q[i - 2], Q[i - 3]) + A[i]
            Q[i] = P[i - 1] + A[i]
        return max(P[n - 2], P[n - 1], Q[n - 2], Q[n - 1]))

num = int(raw_input())
wine = []
for i in range (num):
    wine.append(int(raw_input()))
print wine_point2(wine)