class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned long long> dp(amount + 1, LONG_LONG_MAX);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int x: coins){
		//dp[i-x] + 1 because we're using one more coin
                if(!(i-x < 0))
                    dp[i] = min(dp[i], dp[i-x]+1);
            }
        }
        return dp[amount] == LONG_LONG_MAX ? -1 : dp[amount];
    }
};
