class Solution:
    def dfs(self, g, r, c, col):
        rows, cols = len(g), len(g[0])
        if (r < 0) or (c < 0) or (r >= rows) or (c >= cols) or (g[r][c] != col):
            return
        g[r][c] = -1
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        for k in range(4):
            self.dfs(g, r + dx[k], c + dy[k], col)
    
    
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        rows, cols = len(image), len(image[0])
        fill_color = image[sr][sc]
        self.dfs(image, sr, sc, fill_color)
        for i in range(rows):
            for j in range(cols):
                if image[i][j] == -1:
                    image[i][j] = color
        return image