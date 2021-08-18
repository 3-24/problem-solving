from sys import stdout

def solve():
    n,k = map(int,input().split())
    
    checksum = 0

    for x in range (n):
        question = x ^ checksum
        checksum = x
        print(question)
        stdout.flush()
        ans = int(input())
        if (ans == 1):
            break
        else:
            continue


def main():
    t = int(input())
    for _ in range (t):
        solve()

main()