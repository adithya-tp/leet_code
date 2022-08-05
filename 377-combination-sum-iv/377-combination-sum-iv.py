class Solution:
    def __init__(self):
        self.arr = None
        self.dp = None
    
    def f(self, target):
        if target == 0:
            return 1
        
        if self.dp[target] != -1:
            return self.dp[target]
        
        self.dp[target] = 0
        for item in self.arr:
            if item <= target:
                ans = self.f(target - item)
                self.dp[target] += self.f(target - item)
        self.dp[target]
    
    def combinationSum4(self, nums: List[int], target: int) -> int:
        self.dp = [-1 for _ in range(target + 1)]
        self.arr = nums
        self.f(target)
        return self.dp[target]