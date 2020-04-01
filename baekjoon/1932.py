def main(tri,n):
    T = []
    for i in range (n):
        if i == 0:
            T.append(tri[0])
        else:
            T.append(tri[i])
            for j in range (i+1):
                if j == 0:
                    T[i][j] += T[i-1][0]
                elif j == i:
                    T[i][j] += T[i-1][j-1]
                else:
                    T[i][j] += max(T[i-1][j-1],T[i-1][j])
    return max(T[n-1])


size = int(raw_input())
triangle = []
for i in range (size):
    tri_temp = map(int,raw_input().split())
    triangle.append(tri_temp)
print main(triangle,size)

'''
3
1
1 2
1 2 3
'''