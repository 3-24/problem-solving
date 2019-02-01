def init(a,tree,node,start,end):
    print tree
    if start == end:
        tree[node] = a[start]
        return tree[node]
    else:
        tree[node] = init(a,tree,node*2,start,(start+end)/2) \
        + init(a,tree,node*2+1,(start+end)/2+1,end)
        return tree[node]

def sum(tree,node,start,end,left,right):
    if left>end or right<start:
        return 0
    elif left <= start and end <= right:
        return tree[node]
    return sum(tree,node*2,start,(start+end)/2,left,right) \
    + sum(tree,node*2+1,(start+end)/2+1,end,left,right)\

def update(tree,node,start,end,index,diff):
    if index < start or end < index: return
    tree[node] += diff
    if start != end:
        update(tree,node*2,start,(start+end)/2,index,diff)
        update(tree,node*2+1,(start+end)/2+1,end,index,diff)

def main():
    import sys
    input = sys.stdin.readline

    n,m,k = map(int,input().split())
    A = [int(input()) for _ in xrange(n)]

    T = [None] * (2*n)

    init(A,T,1,0,n-1)

    for i in xrange (m+k):
        input = raw_input().split()
        a,b,c = int(input[0]),int(input[1]),int(input[2])
        if a == 1: # change bth nbr to c
            b -= 1
            diff = c-A[b]
            A[b] = c
            update(T,1,0,n-1,b,diff)
        elif a == 2:
            print sum(T,1,0,n-1,b-1,c-1)
    return 0

main()
