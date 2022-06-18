class Solution:
    def __init__(self):
        self.rows = None
        self.cols = None
        
    def dfs(self, g, r, c):
        if (r < 0) or (c < 0) or (r >= self.rows) or (c >= self.cols) or g[r][c] != "1":
            return
        
        g[r][c] = "-1"
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        for k in range(4):
            self.dfs(g, r + dx[k], c + dy[k])
        
    def numIslands(self, grid: List[List[str]]) -> int:
        self.rows, self.cols = len(grid), len(grid[0])
        
        islands = 0
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] == "1":
                    self.dfs(grid, i, j)
                    islands += 1
                    
        return islands