class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        maxh = 0
        maxw = 0
        
        horizontalCuts.sort()
        verticalCuts.sort()
        
        prev = 0
        for hc in horizontalCuts+[h]:
            maxh = max(hc - prev, maxh)
            prev = hc
        
        prev = 0
        for vc in verticalCuts+[w]:
            maxw = max(vc - prev, maxw)
            prev = vc

        
        return (maxw * maxh) % (10**9 + 7)