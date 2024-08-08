def submain():
    n = int(input())
    s = input()
    
    arr = []
    
    kind = None
    count = 0
    for i in range(n):
        new_kind = s[i]
        
        if new_kind == kind:
            count += 1
        else:
            if kind is not None:
                arr.append((kind, count))
            kind = new_kind
            count = 1
    
    arr.append((kind, count))
    
    ans = 0
    lazy = []
    
    for (k, c) in arr:
        if (c % 2 == 0):
            if (lazy == []):
                if (k == 'T'): ans += c // 2
            else:
                if (lazy[-1][0] != k):
                    ans += c // 2
                lazy[-1][1] += c
        else:
            if (lazy == []):
                if (k == 'T'): lazy.append([k, c])
            else:
                if (lazy[-1][0] == k):
                    lazy[-1][1] += c
                else:
                    lazy.append([k, c])
        
        while (len(lazy) != 0):
            k, c = lazy[-1]
            if (c % 2 != 0): break
            lazy.pop()
            if (lazy == []):
                if (k == 'T'): ans += c // 2
            else:
                if (lazy[-1][0] != k):
                    ans += c // 2
                lazy[-1][1] += c

    if (lazy != []):
        print("-1")
    else:
        print(ans)


def main():
    n = int(input())
    for _ in range(n):
        submain()

main()