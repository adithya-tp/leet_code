class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int rows=A.size(), cols = A[0].size();
        int temp;
        vector<vector<int>> at(cols, vector<int>(rows, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                at[j][i] = A[i][j];
            }
        }
        return at;
    }
};
