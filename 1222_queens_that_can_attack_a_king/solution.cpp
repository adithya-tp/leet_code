    class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> queen_mat(8, vector<int>(8, 0));
        for(vector<int> i : queens){
            queen_mat[i[0]][i[1]] = 1;
        }
        vector<int> dir_x = {-1, 0, 1};
        vector<int> dir_y = {-1, 0, 1};
        int flag = 0;
        vector<vector<int>> attacks;
        vector<int> pos = king;
        for(int i : dir_x){
            for(int j : dir_y){
                if(i == 0 && j == 0)
                    continue;
                while(pos[0] >= 0 && pos[0] <= 7 && pos[1]>=0 && pos[1]<=7 && flag == 0){
                    if(queen_mat[pos[0]][pos[1]] == 1){
                        attacks.push_back(pos);
                        flag = 1;
                    }
                    pos[0] += i;
                    pos[1] += j;
                }
                pos = king;
                flag = 0;
            }
        }
        return attacks;
    }
};


