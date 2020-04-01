def stair_point(li):
    R=[]
    l = len(li)
    for i in range (l):
        if i == 0:
            R.append([li[0]]*2)
        elif i == 1:
            R.append([li[1],li[0]+li[1]])
        else:
            r1 = max(R[i-2])+li[i]
            r2 = R[i-1][0]+li[i]
            R.append([r1,r2])
    return max(R[l-1])


stair_num = int(raw_input())
stair = []
for i in range (stair_num):
    stair.append(int(raw_input()))
print stair_point(stair)