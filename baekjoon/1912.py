'''
def maxsum(li):
    accure = []
    l = len(li)
    for i in range (l):
        const = 0
        for j in range (i):
            const += li[j]
        accure.append(const)
    max = accure[1]-accure[0]
    for loop1 in range (l):
        for loop2 in range (loop1 + 1 , l):
            if accure[loop2]-accure[loop1] > max:
                max = accure[loop2] - accure[loop1]
    return max
'''

def maxsum(li):
    accure = []
    l = len(li)
    for i in range (l):
        if i == 0:
            accure.append(li[i])
        else:
            accure.append(max(accure[i-1]+li[i],li[i]))
    return max(accure)

n = raw_input()
numbers = map(int,raw_input().split())
print maxsum(numbers)