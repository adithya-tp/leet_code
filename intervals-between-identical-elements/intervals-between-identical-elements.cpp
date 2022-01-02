class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> indices;
        
        int len = arr.size();
        
        for(int i = 0; i < len; i++) {
            indices[arr[i]].push_back(i);
        }
        vector<long long> ans(len);
        
        for(auto k : indices) {
            int vec_len = k.second.size();
            vector<long long> pref(vec_len);
            vector<long long> suf(vec_len);
            for(int i = 1; i < vec_len; i++) {
                pref[i] += pref[i - 1] + k.second[i - 1];
                suf[vec_len - i - 1] += suf[vec_len - i] + k.second[vec_len - i];
            }
            
            for(long long i = 0; i < vec_len; i++) {
                int ans_idx = k.second[i];
                long long left_sum = (i * k.second[i]) - pref[i];
                long long right_sum = suf[i] - ((vec_len - i - 1) * k.second[i]);
                ans[ans_idx] = left_sum + right_sum;
            }
        }
        
        return ans;
    }
};