#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> dp_grid(rows, vector<int>(cols,0));
    for(int i = 0; i < rows; i++){
	for(int j = 0; j < cols; j++){
	    dp_grid[i][j] = grid[i][j];
	    if(i == 0 && j == 0)
		continue;
	    if(i > 0 && j > 0){
		dp_grid[i][j] += min(dp_grid[i-1][j], dp_grid[i][j-1]);
	    }
	    else if(i - 1 < 0){
		dp_grid[i][j] += dp_grid[i][j-1];
	    }
	    else{
		dp_grid[i][j] += dp_grid[i - 1][j];
	    }
	}
    }
    cout <<  dp_grid[rows - 1][cols - 1];
}
