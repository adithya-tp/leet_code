class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> pref(len), suf(len);
        pref[0] = 1;
        suf[len - 1] = 1;
        for(int i = 1; i < len; i++) {
            pref[i] = pref[i - 1] * nums[i - 1];
            suf[len - i - 1] = suf[len - i] * nums[len - i];
        }
        
        vector<int> ans(len);
        for(int i = 0; i < len; i++) {
            ans[i] = pref[i] * suf[i];
        }
        return ans;
    }
};