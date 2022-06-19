class Solution:
    def dfs(self, g, r, c):
        rows, cols = len(g), len(g[0])
        if (r < 0) or (c < 0) or (r >= rows) or (c >= cols) or (g[r][c] != 1):
            return 0
        
        g[r][c] = -1
        ans = 1
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        for k in range(4):
            ans += self.dfs(g, r + dx[k], c + dy[k])
        return ans
    
    
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        ans = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]:
                    ans = max(ans, self.dfs(grid, i, j))
                    
        return ans
                    
                    