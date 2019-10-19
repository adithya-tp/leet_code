class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        long long up, left;
        vector<vector<long long>> dp_grid(m, vector<long long>(n,0));
        if(n == 0)
            return 1;
        if(obstacleGrid[0][0] == 1)
            return 0;
        if(obstacleGrid[m-1][n-1] == 1)
            return 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp_grid[i][j] = INT_MAX;
                }
            }
        }
        dp_grid[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp_grid[i][j] != INT_MAX){
                    if(i > 0 && j > 0){
                        up = dp_grid[i-1][j];
                        left = dp_grid[i][j-1];
                        bool bool_up = (up == INT_MAX);
                        bool bool_left = (left == INT_MAX);
                        if(bool_up && !bool_left)
                            dp_grid[i][j] += left;
                        else if(!bool_up && bool_left)
                            dp_grid[i][j] += up;
                        else if(!bool_up && !bool_left)
                            dp_grid[i][j] += up + left;
                    }
                    else if(i > 0){
                        up = dp_grid[i-1][j];
                        if(up != INT_MAX)
                            dp_grid[i][j] += up;
                    }
                    else if(j > 0){
                        left = dp_grid[i][j-1];
                        if(left != INT_MAX)
                            dp_grid[i][j] += left;
                    }
                }
            }
        }
        return dp_grid[m-1][n-1];
    }
};
