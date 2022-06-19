class Solution:
    def good(self, arr, k, h):
        time = 0
        for val in arr:
            time += (val // k) + (val % k > 0)
        return time <= h
            
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 0
        r = max(piles)
        while l + 1 < r:
            mid = l + (r - l) // 2
            if self.good(piles, mid, h):
                r = mid
            else:
                l = mid
        return r