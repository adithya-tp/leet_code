class Solution:
    def in_bounds(self, r, c, rows, cols):
        return (r >= 0) and (c >= 0) and (r < rows) and (c < cols)
    
    def maxDistance(self, grid: List[List[int]]) -> int:
        qx, qy = deque(), deque()
        rows, cols = len(grid), len(grid[0])
        vis = [[False for _ in range(cols)] for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]:
                    vis[i][j] = True
                    qx.append(i)
                    qy.append(j)
        
        level = -1
        found_water = False
        d = [-1, 0, 1, 0, -1]
        
        while len(qx):
            level += 1
            level_size = len(qx)
            for _ in range(level_size):
                px = qx.popleft()
                py = qy.popleft()
                if grid[px][py] == 0:
                    found_water = True
                for k in range(4):
                    nx = px + d[k]
                    ny = py + d[k + 1]
                    if self.in_bounds(nx, ny, rows, cols) and not vis[nx][ny]:
                        vis[nx][ny] = True
                        qx.append(nx)
                        qy.append(ny)
        
        return level if found_water else -1