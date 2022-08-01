class Solution:
    def __init__(self):
        self.g = None
    
    @lru_cache(None)
    def pathSum(self, r, c):
        rows, cols = len(self.g), len(self.g[0])
        if (r >= rows) or (c >= cols):
            return 1e9
        if (r, c) == (rows - 1, cols - 1):
            return self.g[r][c]
        return min(self.pathSum(r + 1, c), self.pathSum(r, c + 1)) + self.g[r][c]
        
    
    def minPathSum(self, grid: List[List[int]]) -> int:
        self.g = grid
        return self.pathSum(0, 0)