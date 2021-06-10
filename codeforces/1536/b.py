def solve():
    k = int(input())
    s = input()
    X = set([])

    for i in range (k):
        X.add(s[i])
    
    for i in range (k-1):
        X.add(s[i:i+2])
    
    for i in range (k-2):
        X.add(s[i:i+3])
    
    l = 1
    success =False
    for i in range (26):
        if not chr(i+97) in X:
            key = chr(i+97)
            success = True
            break
    
    if not success:
        for i in range (26):
            for j in range (26):
                if not chr(i+97)+chr(j+97) in X:
                    key = chr(i+97) + chr(j+97)
                    success = True
                    break
            if success:
                break
    if not success:
        for i in range (26):
            for j in range (26):
                for k in range (26):
                    if not chr(i+97)+chr(j+97)+chr(k+97) in X:
                        key = chr(i+97) + chr(j+97) + chr(k+97)
                        success = True
                        break
                if success:
                    break
            if success:
                break
            
    
    print(key)


def main():
    n = int(input())
    while (n):
        solve()
        n -= 1

main()