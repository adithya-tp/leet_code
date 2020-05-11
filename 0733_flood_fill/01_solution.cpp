class Solution {
public:
    vector<int> dr = {1, 0, -1, 0};
    vector<int> dc = {0, 1, 0, -1};
    void floodFiller(vector<vector<int>>& image, int sr, int sc, int currentColor, int newColor) {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size())
            return;
        if(image[sr][sc] != currentColor)
            return;
        image[sr][sc] = newColor;
        for(int d = 0; d < 4; d++) {
            floodFiller(image, sr + dr[d], sc + dc[d], currentColor, newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int currentColor = image[sr][sc];
        floodFiller(image, sr, sc, currentColor, -1);
        for(int i = 0; i < image.size(); i++) {
            for(int j = 0; j < image[0].size(); j++) {
                if(image[i][j] == -1)
                    image[i][j] = newColor;
            }
        }
        return image;
    }
};
