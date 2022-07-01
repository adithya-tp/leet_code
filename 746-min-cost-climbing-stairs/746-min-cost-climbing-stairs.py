class Solution:
    def __init__(self):
        self.c = None
    
    @lru_cache(None)
    def f(self, idx):
        if idx >= len(self.c):
            return 0
        return self.c[idx] + min(self.f(idx + 1), self.f(idx + 2))
    
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        self.c = cost
        return min(self.f(0), self.f(1))
        