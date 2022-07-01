class Solution:
    def __init__(self):
        self.default = [1e9, 1e9, 0, 0]
        self.coords = None
        
    def dfs(self, g, r, c):
        rows, cols = len(g), len(g[0])
        if (r < 0) or (c < 0) or (r >= rows) or (c >= cols) or (g[r][c] != 1):
            return
        funcs = [min, max]
        comps = [r, c]
        for k in range(4):
            self.coords[k] = funcs[k//2](self.coords[k], comps[k % 2])
        g[r][c] = 0
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        for k in range(4):
            self.dfs(g, r + dx[k], c + dy[k])
    
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        rows, cols = len(land), len(land[0])
        ans = []
        for i in range(rows):
            for j in range(cols):
                if land[i][j]:
                    self.coords = self.default.copy()
                    self.dfs(land, i, j)
                    ans.append(self.coords.copy())
                    self.coords = self.default.copy()
        return ans