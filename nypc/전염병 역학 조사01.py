from __future__ import print_function
import sys

N,M = map(int,raw_input().split())
T = [sys.maxint]*(N+1)
T[1] = 0
count = 1
stack = [[] for i in xrange (N+1)]


for _ in xrange(M):
    a,b,c = map(int,raw_input().split())
    if T[a] <= c:
        T[b] = min(T[b], c)
        count += 1
    elif T[b] <= c:
        T[a] = min(T[a], c)
        count += 1
    else:
        stack[a].append((b,c))
        stack[b].append((a,c))

prev_count = count

while True:
    for meeting in stack:
        a,b,c = meeting
        if T[a] <= c:
            T[b] = min(T[b],c)
            count += 1
            stack.remove(meeting)
        elif T[b] <= c:
            T[a] = min(T[a],c)
            count += 1
            stack.remove(meeting)
    if prev_count == count:
        break
    prev_count = count

for i in xrange (1,N+1):
    if T[i] != sys.maxint:
        print (i,end=' ')