class Solution:
    def __init__(self):
        self.mod = int(1e9 + 7)
        self.arr = None
        self.member = None
    
    @lru_cache(None)
    def dfs(self, root_val):
        ans = 1
        for val in self.arr:
            other_val = root_val // val
            if (other_val in self.member) and (root_val % val == 0):
                ans += (self.dfs(val) * self.dfs(other_val))
        return ans
    
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        self.arr = arr
        self.member = {x: i for i,x in enumerate(arr)}
        total = 0
        for val in arr:
            total += self.dfs(val)
        return total % self.mod
        
        
        