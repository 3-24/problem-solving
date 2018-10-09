def main(N):
    R1=[0,1]
    R0=[0,0]
    for i in range (2,N+1):
        R0.append(R0[i-1]+R1[i-1])
        R1.append(R0[i-1])
    return R0[N]+R1[N]

n = int(raw_input())
print main(n)