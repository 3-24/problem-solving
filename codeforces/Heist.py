from sys import stdin
input = stdin.readline
n = int(input())
L = list(map(int,input().split()))
print(max(L)-min(L)+1-n)
