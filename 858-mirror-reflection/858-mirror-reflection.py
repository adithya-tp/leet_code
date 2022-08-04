class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        right = 1
        left = 1
        while left * p != right * q:
            right += 1
            left = (right * q) // p
        
        if left % 2 == 0:
            return 0
        else:
            if right % 2 == 0:
                return 2
            else:
                return 1