class Solution:
    def dfs(self, g, r, c, col):
        rows, cols = len(g), len(g[0])
        if (r < 0) or (c < 0) or (r >= rows) or (c >= cols) or (g[r][c] != col):
            return
        
        g[r][c] = 1
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        for k in range(4):
            self.dfs(g, r + dx[k], c + dy[k], col)
            
    def is_border_cell(self, r, c, rows, cols):
        return (r == 0) or (r == rows - 1) or (c == 0) or (c == cols - 1)
    
    def closedIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        
        # flood fill islands on the edges
        for i in range(rows):
            for j in range(cols):
                if self.is_border_cell(i, j, rows, cols) and (grid[i][j] == 0):
                    self.dfs(grid, i, j, 0)
        
        # count number of remaining islands
        count = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 0:
                    self.dfs(grid, i, j, 0)
                    count += 1
        return count
        