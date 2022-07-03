class Solution:
    
    def __init__(self):
        self.arr = None
    
    @lru_cache(None)
    def f1(self, idx):
        if idx >= len(self.arr) - 1:
            return 0
        
        return max(self.arr[idx] + self.f1(idx + 2), self.f1(idx + 1))
    
    @lru_cache(None)
    def f2(self, idx):
        if idx >= len(self.arr) - 1:
            return 0
        
        return max(self.arr[idx] + self.f2(idx + 2), self.f2(idx + 1))
        
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        self.arr = nums
        val1 = self.f1(0)
        self.arr = self.arr[::-1]
        val2 = self.f2(0)
        return max(val1, val2)