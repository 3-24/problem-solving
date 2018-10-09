def main(n):
    accure = []
    for i in range (n):
        if i == 0:
            accure.append([0,1,1,1,1,1,1,1,1,1])
        else:
            A = accure[i-1]
            new_accure = [None] * 10
            new_accure[0] = A[1]
            new_accure[9] = A[8]
            for j in range (1,9):
                new_accure[j] = A[j-1] + A[j+1]
            accure.append(new_accure)
    sum = 0
    for k in range (0,10):
        sum += accure[n-1][k]
    return sum % 1000000000

num = int(raw_input())
print main(num)