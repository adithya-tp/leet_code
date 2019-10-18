class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp_grid(rows, vector<int>(cols,0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                dp_grid[i][j] = grid[i][j];
                if(i > 0 && j > 0){
                    dp_grid[i][j] += min(dp_grid[i-1][j], dp_grid[i][j-1]);
                }
                else if(i > 0){
                    dp_grid[i][j] += dp_grid[i - 1][j];
                }
                else if(j > 0){
                    dp_grid[i][j] += dp_grid[i][j - 1];
                }
            }
        }
        return dp_grid[rows - 1][cols - 1];
    }
};
