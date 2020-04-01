'''def increase(A):
    a = len(A)
    S = []
    for i in range (a):
        if i == 0:
            S.append(1)
        else:
            const = 1
            for j in range (i):
                if S[j]+1 > const and A[j] < A[i]:
                    const = S[j] + 1
            S.append(const)
    return S[-1]


def main():
    n = raw_input()
    sequence = map(int , raw_input().split())
    print increase(sequence)

main()'''
n = raw_input()
sequence = map(int, raw_input().split())
length = len(sequence)
S = []
num = 0
for i in range (length):
    if i == 0:
        S.append(1)
    else:
        const = 1
        for j in range (i):
            if S[j]+1 > const and sequence[j] < sequence[i]:
                const = S[j] + 1
        S.append(const)
    if num<S[i]:
        num = S[i]
print num