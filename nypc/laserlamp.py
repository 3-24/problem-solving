def main():
    ine = raw_input().split()
    W = int(ine[0])
    H = int(ine[1])

    map = [[None]*W for i in xrange(H)]

    for i in xrange (H):
        s = str(raw_input())
        for j in xrange (W):
            if s[j] == '.':
                map[i][j] = 0
            elif s[j] == '/':
                map[i][j] = 1
            elif s[j] == '\\':
                map[i][j] = 2
            elif str(s[j]) == 'O':
                map[i][j] = 3
                a, b = i,j

    def pathfinder(I):
        x,y,dir = I[0],I[1],I[2]
        if x is None:
            return [None]*3
        if dir == 'U':
            while True:
                y -= 1
                if map[y][x] == 1:
                    return [x,y,'R']
                elif map[y][x] == 2:
                    return [x,y,'L']
                elif map[y][x] == 0 and y == 0:
                    return [x,-1,'U']
                elif map[y][x] == 3 and y != I[1]:
                    return [None]*3
        elif dir == 'D':
            while True:
                y += 1
                if map[y][x] == 1:
                    return [x,y,'L']
                elif map[y][x] == 2:
                    return [x,y,'R']
                elif map[y][x] == 0 and y == H-1:
                    return [x,-1,'D']
                elif map[y][x] == 3 and y != I[1]:
                    return [None]*3
        elif dir == 'L':
            while True:
                x -= 1
                if map[y][x] == 1:
                    return [x,y,'D']
                elif map[y][x] == 2:
                    return [x,y,'U']
                elif map[y][x] == 0 and x == 0:
                    return [-1,y,'L']
                elif map[y][x] == 3 and x != I[0]:
                    return [None]*3
        elif dir == 'R':
            while True:
                x += 1
                if map[y][x] == 1:
                    return [x,y,'U']
                elif map[y][x] == 2:
                    return [x,y,'D']
                elif map[y][x] == 0 and x == W-1:
                    return [-1,y,'R']
                elif map[y][x] == 3 and x != I[0]:
                    return [None]*3

    guide = [[a,b,'U'],[a,b,'D'],[a,b,'L'],[a,b,'R']]

    r = -1

    while r == -1:
        print guide
        for i in xrange (4):
            guide[i] = pathfinder(guide[i])
            if -1 in guide[i]:
                r = i

    print guide[r]
    if guide[r][2] == 'U' or guide[r][2] == 'R':
        print guide[r][2], guide[r][1]
    else:
        print guide[r][2], guide[r][0]


main()
