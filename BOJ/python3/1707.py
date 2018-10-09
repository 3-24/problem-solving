from sys import stdin
input = stdin.readline

test_nbr = int(input()) # number of test cases

def isBipartite():
    # v and e is number of vertexes and edges, respectively.
    v,e = map(int,input().split())

    # None if not colored
    # If colored, there are two bool cases: False and True.
    colorArr = [None for _ in range(v+1)]
    adjacentPoints = [[] for _ in range(v+1)]

    for i in range(e):
        v1, v2 = map(int, input().split()) # edge (v1, v2) is expected input
        adjacentPoints[v1].append(v2)
        adjacentPoints[v2].append(v1)

    queue = []
    node = set([i for i in range(1,v+1)]) # for non-connected graph

    while bool(node): # node is nonempty
        c = node.pop()
        queue.append(c)
        while bool(queue): # queue is nonempty
            start = queue[0]
            for u in adjacentPoints[start]:
                if colorArr[u] is not None:
                    if colorArr[u] is colorArr[start]:
                        return False
                else:
                    colorArr[u] = not colorArr[start]
                    queue.append(u)
            del queue[0]
            if start != c:
                node.remove(start)

    return True


for _ in range(test_nbr):
    print('YES' if isBipartite() else 'NO')