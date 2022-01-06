class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> road(1010, 0);
        for(auto trip : trips) {
            road[trip[1]] += trip[0];
            road[trip[2]] -= trip[0];
        }
        
        int curr_cap = 0;
        for(int i = 0; i < road.size(); i++) {
            curr_cap += road[i];
            if (curr_cap > capacity) {
                return false;
            }
        }
        return true;
    }
};