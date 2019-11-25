class Solution {
public:
    void flood(vector<vector<int>>& image, int sr, int sc, int oc, int nc){
        vector<int> dr = {1, 0, -1, 0};
        vector<int> dc = {0, 1, 0, -1};
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        if(image[sr][sc] != oc)
            return;
        image[sr][sc] = nc;
        for(int i = 0; i < 4; i++)
            flood(image, sr+dr[i], sc+dc[i], oc, nc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int original_color = image[sr][sc];
        flood(image, sr, sc, original_color, newColor+1);
        flood(image, sr, sc, newColor+1, newColor);
        return image;
    }
};
