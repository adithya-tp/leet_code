class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> layers;
        for(auto row : bank) {
            int count = 0;
            for(char c : row) {
                if(c == '1') {
                    count++;
                }
            }
            if(count) layers.push_back(count);
        }
        
        int ans = 0;
        for(int i = 1; i < layers.size(); i++) {
            ans += layers[i] * layers[i - 1];
        }
        return ans;
    }
};