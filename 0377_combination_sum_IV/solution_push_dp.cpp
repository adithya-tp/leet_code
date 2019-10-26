class Solution {
public:
    // using the forward / push dynamic programming method
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 0; i < target + 1; i++){
            for(int x: nums){
                if(i+x < target + 1)
                    dp[i+x] += dp[i];
            }
        }
        return dp[target];
    }
};
