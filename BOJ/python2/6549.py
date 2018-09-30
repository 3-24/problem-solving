import sys
input = sys.stdin.readline

while True:
    I = input()
    n = int(I[0])
    if n == 0:
        break
    m = 0
    A = [0 for _ in xrange(n)] + map(int, I[2:].split())
    for i in xrange (n-1,0,-1):
        A[i] = min(A[i << 1], A[i << 1 | 1])

    def find_min(i,j):
        a,b = i,j
        label = -1
        return_val = 0
        while a <= b:
            if a & 1:
                if return_val <= A[a]:
                    label, return_val = a, A[a]
            if not b & 1:
                if return_val <= A[b]:
                    label, return_val = b, A[b]
            a = a + 1 >> 1
            b = b - 1 >> 1
        return label, return_val

    def ongoing(start,end):
        return min(find_min(i,j))

    print m