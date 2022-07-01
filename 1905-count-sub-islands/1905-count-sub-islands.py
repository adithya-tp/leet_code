class Solution:
    
    def dfs(self, g, r, c):
        rows, cols = len(g), len(g[0])
        if (r < 0) or (c < 0) or (r >= rows) or (c >= cols) or (g[r][c] != 1):
            return
        g[r][c] = 0
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        for k in range(4):
            self.dfs(g, r + dx[k], c + dy[k])
    
    def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
        rows, cols = len(grid2), len(grid2[0])
        for i in range(rows):
            for j in range(cols):
                if grid2[i][j] and (not grid1[i][j]):
                    self.dfs(grid2, i, j)
        
        ans = 0
        for i in range(rows):
            for j in range(cols):
                if grid2[i][j]:
                    ans += 1
                    self.dfs(grid2, i, j)
        return ans