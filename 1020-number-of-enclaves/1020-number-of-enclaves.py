class Solution:
    def __init__(self):
        self.count = 0
    
    def dfs(self, g, r, c):
        rows, cols = len(g), len(g[0])
        if (r < 0) or (c < 0) or (r >= rows) or (c >= cols):
            return True
        elif g[r][c] != 1:
            return False
        
        self.count += 1
        g[r][c] = -1
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        curr = False
        for k in range(4):
            curr = self.dfs(g, r + dx[k], c + dy[k]) or curr
        return curr
    
    
    def numEnclaves(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        ans = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    oob = self.dfs(grid, i, j)
                    if not oob:
                        ans += self.count
                    self.count = 0
                    
        return ans