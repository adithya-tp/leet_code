class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size(), longest = triangle[len - 1].size(), LARGE = 1e5;
        vector<vector<int>> ans = triangle;
        for(int i = 1; i < len; i++) {
            cout << "row: " << i << "\n";
            for(int j = 0; j <= i; j++) {
                int up = i - 1, left = j - 1, left_val = LARGE, up_val = LARGE;
            
                if(up >= 0 && j <= i - 1) {
                    up_val = triangle[i][j] + ans[up][j];
                }
                
                if(up >= 0 && left >= 0) {
                    left_val = triangle[i][j] + ans[up][left];
                }
                ans[i][j] = min(left_val, up_val);
            }
        }
        
        int ret = LARGE;
        for(int j = 0; j < longest; j++) {
            ret = min(ret, ans[len - 1][j]);
        }
        return ret;
    }
};