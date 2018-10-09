def atk_or_def(d, A):  # 0 to atk, 1 to def
    return map(lambda x: x[d], A)


def proper_split(s):
    if s == 'X':
        return [0,0]
    return map(int,s[1:].split('/'))


def scan_board():
    ATK = [[0 for i in xrange(3)] for j in xrange(4)]
    DEF = ATK[:]
    CONFIG = ATK[:]

    def config(s):
        if s[0] == 'M': return 1
        elif s[0] == 'O': return 2

    for i in xrange(4):
        P = raw_input().split()
        M = map(proper_split, P)

        CONFIG[i] = map(config, P)
        ATK[i],DEF[i] = atk_or_def(0,M), atk_or_def(1,M)

    return ATK, DEF, CONFIG

ATK, DEF, CONFIG = scan_board()

_ = int(raw_input())
ADD_PIECE = atk_or_def(0, map(proper_split,raw_input().split()))
wildcard = max(ADD_PIECE)
CONFIG_BINGO = [[0 for i in xrange(3)] for j in xrange(4)]
CONFIG_EMPTY = [[[0,0] for i in xrange(3)] for j in xrange(4)] # number, point
present_point = 0


def check(coordinate, x,y):
    global present_point
    i,j = coordinate
    if CONFIG[i + x][j + y] == 1:
        if CONFIG[i + x + x][j + y + y] == 1:
            point = ATK[i][j] + ATK[i + x][j + y] + ATK[i + x + x][j + y + y]
            CONFIG_BINGO[i][j] += point
            CONFIG_BINGO[i+x][j+y] += point
            CONFIG_BINGO[i+x+x][j+y+y] += point
            present_point += point
        else:
            CONFIG_EMPTY[i+x+x][j+y+y][0] += 1
            CONFIG_EMPTY[i+x+x][j+y+y][1] += ATK[i][j] + ATK[i + x][j + y]
    else:
        if CONFIG[i + x + x][j + y + y] == 1:
            CONFIG_EMPTY[i+x][j+y][0] += 1
            CONFIG_EMPTY[i+x][j+y][1] += ATK[i][j] + ATK[i + x + x][j + y + y]

def empty_check(coordinate, x,y):
    i,j = coordinate
    if CONFIG[i + x][j + y] == 1:
        if CONFIG[i + x + x][j + y + y] == 1:
            CONFIG_EMPTY[i][j][0] += 1
            CONFIG_EMPTY[i][j][1] += ATK[i+x][j+y] + ATK[i+x+x][j+y+y]

for i in xrange(4):
    for j in xrange(3):
        if CONFIG[i][j] == 1:
            if j == 0:
                # horizontal
                check((i,j),0,1)
                if i <= 1:
                    check((i,j),1,0) # vertical
                    check((i,j),1,1) # diagonal down
                else:
                    check((i,j),-1,1) # diagonal up
            else:
                if i <= 1:
                    check((i,j),1,0)
        else:
            if j == 0:
                empty_check((i,j),0,1)
                if i <= 1:
                    empty_check((i,j),1,0) # vertical
                    empty_check((i,j),1,1) # diagonal down
                else:
                    empty_check((i,j),-1,1) # diagonal up
            else:
                if i <= 1:
                    empty_check((i,j),1,0)


max_diff = 0

for i in xrange(4):
    for j in xrange(3):
        count, bingo_point = CONFIG_EMPTY[i][j]
        if CONFIG_EMPTY[i][j][0] != 0:
            if CONFIG[i][j] is None: # wildcard
                temp = wildcard * count + bingo_point
                if max_diff < temp: max_diff = temp
            if CONFIG[i][j] != 1: #move card
                for di in xrange(-1,2):
                    for dj in xrange(-1,2):
                        pi,pj = i + di, j + dj
                        if 0 <= pi < 4 and 0 <= pj < 3 and not (di == 0 and dj == 0):
                            if CONFIG[pi][pj] == 1:
                                if ATK[i][j] < DEF[pi][pj] and DEF[i][j] < ATK[pi][pj]:
                                    temp = ATK[pi][pj] * count + bingo_point - CONFIG_BINGO[pi][pj]
                                    if 0<= i - di < 4 and 0<= j - dj < 3 and CONFIG[i-di][j-dj] == 1:
                                        temp -= ATK[pi][pj] * 2 + ATK[i-di][j-dj]
                                    if 0<= i+ 2*di < 4 and 0 <= j + 2 * dj < 3 and CONFIG[i + 2 *di][j + 2 * dj] == 1:
                                        temp -= ATK[pi][pj] * 2 + ATK[i+2*di][j+2*dj]
                                    if max_diff < temp: max_diff = temp

print max_diff + present_point