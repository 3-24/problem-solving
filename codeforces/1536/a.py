from functools import reduce
from math import gcd

def solve():
    k = int(input())
    a = list(map(int, input().split()))
    success = True
    for i in range(len(a)):
        if (a[i] < 0):
            success = False
    if success:
        if len(a) >= 2:
            g = reduce(lambda x,y: gcd(x,y), a)

            if (min(a) == 0):
                L = [0]
                count = 1
            else:
                L = []
                count = 0
            
            count += max(a) // g
            if (count > 300):
                success = False
            else:
                success = True
                for i in range(1, max(a) // g + 1):
                    L.append(i*g)   
        else:
            success = True
            L = a
    
    if success:
        print("YES")
        print(len(L))
        for x in L:
            print(x, end=" ")
        print("")
    else:
        print("NO")




def main():
    n = int(input())
    while (n):
        solve()
        n-=1

main()