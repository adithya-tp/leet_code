class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int temp;
        int rows = A.size();
        int cols = A[0].size();
        int cols_lim = cols % 2 == 0 ? cols / 2 - 1 : cols / 2;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j <= cols_lim; j++){
                temp = 1 - A[i][cols - j - 1];
                A[i][cols - j - 1] = 1 - A[i][j];
                A[i][j] = temp;
            }
        }
        return A;
    }
};
