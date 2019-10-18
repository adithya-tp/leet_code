class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp_grid(m, vector<int>(n,0));
        dp_grid[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i > 0 && j > 0){
                    dp_grid[i][j] += dp_grid[i-1][j] + dp_grid[i][j-1];
                }
                else if(i > 0){
                    dp_grid[i][j] += dp_grid[i-1][j];
                }
                else if(j > 0){
                    dp_grid[i][j] += dp_grid[i][j-1];
                }
            }
        }
        return dp_grid[m-1][n-1];
    }
};

