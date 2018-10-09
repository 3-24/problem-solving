import sys
input = sys.stdin.readline

n, m = map(int, input().split())

P = [i for i in range(n + 1)]
R = [0] * (n + 1)


def find(a):
    if P[a] == a:
        return a
    P[a] = find(P[a])
    return P[a]


def union(x,y):
    x, y = find(x), find(y)
    if not x == y:
        if R[x] > R[y]:
            P[y] = x
        else:
            P[x] = y
            if R[x] == R[y]:
                R[y] += 1


for _ in range(m):
    boo, a, b = map(int, input().split())
    if boo:
        print('YES') if find(a) == find(b) else print('NO')
    else:
        union(a, b)
