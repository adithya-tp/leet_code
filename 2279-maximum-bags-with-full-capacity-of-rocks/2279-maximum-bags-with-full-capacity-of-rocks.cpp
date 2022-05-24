class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> rem;
        int len = rocks.size();
        for(int i = 0; i < len; i++) {
            rem.push_back(capacity[i] - rocks[i]);
        }
        sort(rem.begin(), rem.end());
        int bags = 0;
        for(int i = 0; i < len; i++) {
            if (rem[i] > additionalRocks) break;
            additionalRocks -= rem[i];
            bags++;
        }
        return bags;
    }
};