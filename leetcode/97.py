class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        @lru_cache(None)
        def aux(i1, i2, i3):
            if (len(i1) + len(i2) != len(i3)):
                return False

            if (i2 == ""):
                return i1 == i3

            c = i2[0]

            result = False

            for i in range(len(i3)):
                if (i3[i] == c):
                    if (i1[:i] != i3[:i]):
                        break
                    
                    result = result or aux(i1[i:], i2[1:], i3[i+1:])
            return result
        
        return aux(s1,s2,s3)
        