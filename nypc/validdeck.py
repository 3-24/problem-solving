def main():
    N = int(raw_input())
    stack = set([])
    for i in xrange(N):
        stack.add(raw_input())
    if len(stack) <= 3:
        print 'valid'
    else:
        print 'invalid'

main()