import sys
input = sys.stdin.readline


def getGraph():
    n = int(input())
    adj = [set([]) for _ in range(n)]
    deg = [-1 for _ in range(n)]
    for i in range(n):
        L = list(map(int,input().split()))
        for j in range(n):
            if L[j]:
                adj[i].add(j)
                deg[i] += 1
    return n,adj,deg # n is |V|


def degreeCheck(n,deg):
    for i in range(n): # even degree and connectivity check
        if deg[i] & 1: return False
    return True


def main():
    n, adj, deg = getGraph()
    if not degreeCheck(n, deg):
        return -1

    node = set([i for i in range(n)])

    def findEulerCycle(u):
        path = [u]
        path_len = 1
        v = u
        while True:
            if deg[v] == 0:
                return -1
            else:
                i = adj[v].pop()
                adj[i].remove(v)
                deg[v] -= 1
                deg[i] -= 1
                path.append(i)
                path_len += 1
                v = i
                node.discard(i)
                if v == u:
                    break

        comp = []
        for i in range(path_len):
            if deg[path[i]] != 0:
                k = findEulerCycle(path[i])
                if k == -1: return -1
                else: comp += k
            else:
                comp += [path[i]]

        return comp

    if not bool(node):
        return -1
    print(" ".join(map(lambda x:str(x+1), findEulerCycle(0))))


print(main())