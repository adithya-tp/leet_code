class Solution:
    def dfs(self, g, r, c):
        rows, cols = len(g), len(g[0])
        if (r < 0) or (c < 0) or (r >= rows) or (c >= cols) or (g[r][c] != 1):
            return 0
        g[r][c] = 0
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        ans = 1
        for k in range(4):
            ans += self.dfs(g, r + dx[k], c + dy[k])
        return ans
    
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        ans = 0
        for i in range(rows):
            for j in range(cols):
                # Flood fill from the boundary land cells to 0
                if (grid[i][j] == 1) and ((i == 0) or (j == 0) or (i == rows - 1) or (j == cols - 1)):
                    self.dfs(grid, i, j)
        
        for i in range(rows):
            for j in range(cols):
                # Add up the number of remaining island sizes
                if grid[i][j]:
                    ans += self.dfs(grid, i, j)
        return ans