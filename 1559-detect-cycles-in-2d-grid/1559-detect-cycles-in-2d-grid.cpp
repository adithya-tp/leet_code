class Solution {
public:
    enum status {
        unvisited = 0,
        explored = 1,
        visited = 2,
    };
    
    bool found_cycle = false;
    
    bool oob(vector<vector<char>>& g, int r, int c) {
        return r < 0 || r >= g.size() || c < 0 || c >= g[0].size();
    }
    
    int to_one_dim(int r, int c, int cols) {
        return r * cols + c;
    }
    
    void dfs(vector<int>& dfs_parent, vector<vector<char>>& g, vector<vector<status>>& vis, int r, int c, char curr_char) {
        vis[r][c] = explored;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int dir = 0; dir < 4; dir++) {
            int nr = r + dx[dir], nc = c + dy[dir];
            if(!oob(g, nr, nc)) {
                if(g[nr][nc] == curr_char) {
                    int cols = g[0].size();
                    if(vis[nr][nc] == explored) {
                        if(dfs_parent[to_one_dim(r, c, cols)] != to_one_dim(nr, nc, cols)) {
                            found_cycle = true;
                            return;
                        }
                    } else {
                        if(vis[nr][nc] == unvisited) {
                            dfs_parent[to_one_dim(nr, nc, cols)] = to_one_dim(r, c, cols);
                            dfs(dfs_parent, g, vis, nr, nc, curr_char);   
                        }
                    }
                }
            }
        }
        vis[r][c] = visited;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<status>> vis(rows, vector<status>(cols, unvisited));
        vector<int> dfs_parent(rows * cols, -1);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(vis[i][j] == unvisited) {
                    dfs(dfs_parent, grid, vis, i, j, grid[i][j]);
                    if(found_cycle) return true;
                }
            }
        }
        return false;
    }
};