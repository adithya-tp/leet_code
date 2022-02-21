class Solution {
public:
    
    bool oob(int r, int c, int rows, int cols) {
        return (r < 0) || (r >= rows) || (c < 0) || (c >= cols);
    }
    
    bool inside(vector<vector<int>>& g, int r, int c, int rows, int cols, int color) {
        bool c1 = (r > 0) && (r < rows - 1) && (c > 0) && (c < cols - 1);
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        
        bool c2 = c1 && true;
        for(int dir = 0; c2 && dir < 4; dir++) {
            int nr = r + dx[dir], nc = c + dy[dir];
            c2 = c2 && (abs(g[nr][nc]) == color);
        }
        return c1 && c2;
    }
    
    void dfs(vector<vector<int>>& g, int r, int c, int curr_col) {
        if(oob(r, c, rows, cols) || g[r][c] != curr_col) return;
        g[r][c] = -curr_col;
                
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir], nc = c + dy[dir];
            dfs(g, nr, nc, curr_col);
        }
        
        if(inside(g, r, c, rows, cols, curr_col)) {
            g[r][c] = curr_col;
        }
    }
    
    
    int rows = 0, cols = 0;
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        rows = grid.size();
        cols = grid[0].size();
        dfs(grid, row, col, grid[row][col]);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] < 0) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
};