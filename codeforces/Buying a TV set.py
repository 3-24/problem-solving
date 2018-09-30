from math import gcd

a,b,x,y = map(int,input().split())
g = gcd(x,y)
x,y = x/g, y/g
print(int(min(a/x,b/y)))
