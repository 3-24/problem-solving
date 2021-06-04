class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        colorGrid = [[0 for _ in range (n)] for _ in range(m)]
        colorDict = {}
        
        def checkColor(x,y):
            if (0 <= x < m and 0 <= y < n):
                return colorGrid[x][y]
            else:
                return 0
            
        
        color = 1
        for i in range (m):
            for j in range(n):
                if (grid[i][j] == 1):
                    color1 = checkColor(i,j-1)
                    color2 = checkColor(i-1,j)
                    if (color1 != 0 and color2 != 0):
                        if (color1 != color2):
                            colorDict[color1] += colorDict[color2]
                            for (x,y) in colorDict[color2]:
                                colorGrid[x][y] = color1
                            colorDict.pop(color2)
                        colorGrid[i][j] = color1
                        colorDict[color1].append((i,j))
                    elif (color1 != 0):
                        colorGrid[i][j] = color1
                        colorDict[color1].append((i,j))
                    elif (color2 != 0):
                        colorGrid[i][j] = color2
                        colorDict[color2].append((i,j))
                    else:
                        colorGrid[i][j] = color
                        colorDict[color] = [(i,j)]
                        color += 1
        
        res = 0
        for c in colorDict:
            if len(colorDict[c]) > res:
                res = len(colorDict[c])
        return res
                