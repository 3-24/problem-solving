import bisect

N,M = map(int,raw_input().split())
meeting_log = [[] for i in xrange(N+1)]
boundary_person = [1]
boundary_time = [0]


for _ in xrange(M):
    a,b,c = map(int,raw_input().split())
    meeting_log[a].append((b,c))
    meeting_log[b].append((a,c))

stack_output = [1]

while boundary_time:
    p,t = boundary_person[0], boundary_time[0]
    del boundary_person[0]
    del boundary_time[0]
    temp = meeting_log[p][:]
    for meet in temp:
        if meet[1] >= t:
            bisect.insort(boundary_time, meet[1])
            if meet[0] not in stack_output:
                bisect.insort(stack_output, meet[0])
            index = bisect.bisect(boundary_time, meet[1])
            boundary_person[index:index] = [meet[0]]
            meeting_log[p].remove(meet)
            meeting_log[meet[0]].remove((p, meet[1]))

print ' '.join(map(str,stack_output))