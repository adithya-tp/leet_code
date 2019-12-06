#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tr_x, tr_y, x, y, i;
    int off_flag = 0;
    string ori, dirs;
    cin >> tr_x >> tr_y;
    vector<vector<int>> scent_mat(tr_x + 1, vector<int>(tr_y + 1, 0)); 
    vector<int> di = {0, 1, 0, -1};
    vector<int> dj = {1, 0, -1, 0};
    vector<char> dir = {'N', 'E', 'S', 'W'};
    while(cin >> x >> y >> ori >> dirs){
        i = ori == "N" ? 0 : (ori == "E" ? 1 : (ori == "S" ? 2 : 3));
        for(char c : dirs){
            if(c == 'R'){
                i = (i + 1) % 4;
            }
            else if(c == 'L'){
                i = (i - 1 + 4) % 4;
            }
            else{
                int x_inc = x + di[i], y_inc = y + dj[i];
                if((x_inc < 0 || x_inc > tr_x || y_inc < 0 || y_inc > tr_y)){
                    if(scent_mat[x][y] == 0){
                        scent_mat[x][y] = 1;
                        off_flag = 1;
                        break;
                    }
                }
                else{
                    x = x_inc;
                    y = y_inc;
                }
            }
        }
        if(off_flag){
            cout << x << " " << y << " " << dir[i] << " " << "LOST" << "\n";
            off_flag = 0;
        }
        else{
            cout << x << " " << y << " " << dir[i] << "\n";
        }
    }
    return 0;
}
