// daaamn this codee UUUGGGGGLYYYYYYY
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(N == 1)
            return 1;
        unordered_map<int, set<int>> trusts;
        unordered_map<int, int> trust_counts;
        int max_count = INT_MIN;
        int max_trusted;
        for(int i = 0; i < trust.size(); i++) {
            int trustee = trust[i][0];
            int trusted = trust[i][1];
            trusts[trustee].insert(trusted);
            trust_counts[trusted]++;
            if(trust_counts[trusted] > max_count) {
                max_count = trust_counts[trusted];
                max_trusted = trusted;
            }
        }
        
        for(int i = 0; i < trust.size(); i++) {
            int trusted = trust[i][1];
            if(trust_counts[trusted] == max_count && trusted != max_trusted) {
                return -1;
            }
        }
        
        for(auto i : trusts) {
            if(i.second.find(max_trusted) == i.second.end()) 
                return -1;
        }
        return max_trusted;
    }
};
