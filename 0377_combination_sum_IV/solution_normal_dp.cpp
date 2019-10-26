class Solution {
public:
    // using normal dp
    int combinationSum4(vector<int>& nums, int target) {
        /* 
        What matters is the sum so far and the not the numbers in that sum. 
        So we use the sum as the dimension of the dp.
        Since we need to find the count, dp[i] would mean the number of ways to reach that state i.
        */
        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            for(int x: nums){
                if(!(i - x < 0))
                    dp[i] += dp[i-x];
            }
        }
        return dp[target];
    }
};
