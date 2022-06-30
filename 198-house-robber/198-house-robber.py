class Solution:
    def __init__(self):
        self.arr = None
    
    @lru_cache(None)
    def f(self, idx: int) -> int:
        """
        What's the maximum amount of money I can
        rob starting from the house at index=idx?
        """
        if idx >= len(self.arr):
            return 0
        
        return max(self.f(idx + 1), self.arr[idx] + self.f(idx + 2))
        
    def rob(self, nums: List[int]) -> int:
        self.arr = nums
        return self.f(0)