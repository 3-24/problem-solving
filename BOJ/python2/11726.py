def main():
    num = int(raw_input())
    print tiling(num) % 10007

def tiling(n):
    T = []
    for i in range (n):
        if i == 0:
            T.append(1)
        elif i == 1:
            T.append(2)
        else:
            T.append(T[i-1]+T[i-2])
    return T[n-1]

main()