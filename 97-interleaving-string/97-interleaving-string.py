class Solution:
    def __init__(self):
        self.s1 = None
        self.s2 = None
        self.s3 = None
    
    @lru_cache(None)
    def f(self, idx1, idx2, idx3):
        if idx3 == len(self.s3):
            return True
        if (idx1 < len(self.s1)) and (idx2 < len(self.s2)):
            if self.s1[idx1] == self.s2[idx2] == self.s3[idx3]:
                return self.f(idx1 + 1, idx2, idx3 + 1) or self.f(idx1, idx2 + 1, idx3 + 1)

            if self.s1[idx1] == self.s3[idx3]:
                return self.f(idx1 + 1, idx2, idx3 + 1)
            elif self.s2[idx2] == self.s3[idx3]:
                return self.f(idx1, idx2 + 1, idx3 + 1)
            return False
        else:
            if (idx1 < len(self.s1)) and (self.s1[idx1] == self.s3[idx3]):
                return self.f(idx1 + 1, idx2, idx3 + 1)
            elif (idx2 < len(self.s2)) and (self.s2[idx2] == self.s3[idx3]):
                return self.f(idx1, idx2 + 1, idx3 + 1)
            return False
    
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if (len(s1) + len(s2) != len(s3)):
            return False
        
        if s1 + s2 == s3:
            return True
        
        c = [0 for _ in range(26)]
        for ch in ''.join([s1, s2]):
            c[ord(ch) - ord('a')] += 1
        
        for ch in s3:
            c[ord(ch) - ord('a')] -= 1
            
        if any(c):
            return False
        
        self.s1 = s1
        self.s2 = s2
        self.s3 = s3
        return self.f(0, 0, 0)