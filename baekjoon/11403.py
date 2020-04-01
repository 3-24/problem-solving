import sys
input = sys.stdin.readline


def getGraph():
    n = int(input())
    A = [None for _ in range(n+1)]
    A[0] = [-1 for _ in range (n+1)]
    for i in range(1,n+1):
        A[i] = [-1] + list(map(int,input().split()))
    return n,A


def isConnected(n,A):
    queue = [0]
    not_visited = set([i for i in range(n)])
    while bool(queue):
        v = queue.pop()
        not_visited.discard(v)
        for i in range(n):
            if A[v][i]:
                if i in not_visited:
                    queue.append(i)
    return not bool(not_visited)


def findPath(a,b,n,A): # BFS
    queue = [a]
    visited = set([])
    I = [-1 for _ in range(n+1)]
    while bool(queue):
        v = queue.pop(0)
        visited.add(v)
        for i in range(1,n+1):
            if A[v][i] and i not in visited:
                I[i] = v
                if i == b: # arrived
                    R = [b]
                    prev = b
                    while True:
                        prev = I[prev]
                        R.append(prev)
                        if prev == a:
                            return list(R.__reversed__())
                queue.append(i)

    return None


def main():
    n,A = getGraph() # n is |V|, A is adjacency graph
    for i in range(n): # even degree check
        if sum(A[i]) & 1:
            return False
    cycle = [0]
    while True:
        start = cycle[-1]
        for i in range(n):
            if A[start][i]:
                pass

n,A = getGraph()
print(A)
print(findPath(1,4,n,A))