a,b = map(int,raw_input().split())

while a*b != 0:
    if a == 1 or b == 1:
        print "POSSIBLE"
        exit()
    else:
        a,b = a%b, b%a

if a == 1:
    print "POSSIBLE"
else:
    print "IMPOSSIBLE"