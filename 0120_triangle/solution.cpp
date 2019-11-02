class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        int top, top_left, top_right;
        int min_sum = INT_MAX;
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < triangle[i].size();j++){
                top = (i - 1 >= 0) && (j < triangle[i-1].size()) ? triangle[i-1][j] : INT_MAX;
                top_left = (i - 1 >= 0) && (j - 1 < triangle[i-1].size()) ? triangle[i-1][j-1] : INT_MAX;
                triangle[i][j] += min(top, top_left);
            }
        }
        for(int j = 0; j < triangle[rows-1].size(); j++)
            min_sum = min(min_sum , triangle[rows-1][j]);
        return min_sum;
    }
};
