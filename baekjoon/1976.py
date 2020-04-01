from sys import stdin
input = stdin.readline

n = int(input()) # n <= 200
m = int(input()) # m <= 1000

PARENT = [i for i in range(n)]
RANK = [0 for _ in range(n)]


def find(a):
    if a == PARENT[a]:
        return a
    PARENT[a] = find(PARENT[a])
    return PARENT[a]


def union(x,y):
    x,y = find(x), find(y)
    if x != y:
        if RANK[x] > RANK[y]:
            PARENT[y] = x
        else:
            PARENT[x] = y
            if RANK[x] == RANK[y]:
                RANK[y] += 1


for i in range(n):
    IN = list(map(int, input().split()))
    for j in range(i,n):
        if IN[j]:
            union(i,j)


PLAN = list(map(int,input().split()))


def isValidPlan():
    for i in range(m-1):
        if find(PLAN[i]-1) != find(PLAN[i+1]-1):
            return 'NO'
    return 'YES'


print(isValidPlan())