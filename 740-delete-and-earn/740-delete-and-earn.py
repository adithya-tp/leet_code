class Solution:
    
    def __init__(self):
        self.arr = None
    
    @lru_cache(None)
    def f(self, idx):
        if idx <= 0:
            return 0
        v1 = (self.arr[idx] * idx) + self.f(idx - 2)
        v2 = self.f(idx - 1)
        return max(v1, v2)
    
    def deleteAndEarn(self, nums: List[int]) -> int:
        nums.sort()
        mx = nums[-1]
        arr = [0 for _ in range(int(10 + 1e5))]
        for val in nums:
            arr[val] += 1
        self.arr = arr
        return self.f(mx)