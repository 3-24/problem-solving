import sys
input = sys.stdin.readline

testnbr = int(input())

for _1 in range(testnbr):
    f = int(input())
    PARENT = dict()
    SIZE = dict()

    def find(x):
        if PARENT[x] == x: return x
        PARENT[x] = find(PARENT[x])
        return PARENT[x]

    def union(a,b):
        x, y = find(a), find(b)
        if not x == y:
            s = SIZE[x] + SIZE[y]
            if SIZE[x] > SIZE[y]:
                PARENT[y] = x
                SIZE[x] = s
            else:
                PARENT[x] = y
                SIZE[y] = s

    def get_size(a):
        return SIZE[find(a)]


    for _2 in range(f):
        a, b = input().split()
        if a not in PARENT:
            PARENT[a] = b
            if b in PARENT:
                SIZE[find(b)] += 1
            else:
                PARENT[b] = b
                SIZE[b] = 2
        elif b not in PARENT: # a는 PARENT에 있다
            PARENT[b] = a
            SIZE[find(a)] += 1
        else: union(a,b)
        print(get_size(a))
