N = int(raw_input())
login, logout = [None]*N, [None]*N

for i in xrange (N):
    login[i], logout[i] = raw_input().split()

merged_log = login + logout
merged_log.sort()
l = 2 * N
count_list = [0] * (l-1)

for i in xrange(N):
    p,q = login[i],logout[i]
    a,b = merged_log.index(p), merged_log.index(q)
    for j in xrange (a,b):
        count_list[j] += 1

start = 0
count = 0
act = False
for k in xrange(l-1):
    if count_list[k] > count:
        count = count_list[k]
        start,end = k, k+1
        act = True
    elif count_list[k] == count and act is True:
        end += 1
    else: act = False

print count

print merged_log[start], merged_log[end]