def getInput(): # get n,m,d, days list
    n,m,d = map(int,input().split())
    A = list(map(int,input().split()))
    return n,m,d,A # len(A) = n


def main(): # sort and greedy
    n,m,d,A = getInput()
    I = [-1 for _ in range(m+1)]
    for i in range(n):
        I[A[i]] = i # inverse permutation
    S = sorted(A)
    RESULT = [None for _ in range(n)]
    color = 0
    queue = []
    for i in range(0,n):
        new_coffee = S[i]
        if i == 0:
            color += 1
            RESULT[I[new_coffee]] = str(color)
            queue.append(new_coffee)
        else:
            target_coffee = queue[0]
            if target_coffee + d >= new_coffee: # new array
                del queue[0]
                queue.append(new_coffee)
                color += 1
                RESULT[I[new_coffee]] = str(color)
                queue.append(new_coffee)
            else: # append
                RESULT[I[new_coffee]] = RESULT[I[target_coffee]]
                queue[target] = new_coffee
                target = candidate.index(min(candidate))

    print(color)
    print(" ".join(RESULT)) if n > 1 else print(RESULT[0])

main()