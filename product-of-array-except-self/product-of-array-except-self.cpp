class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        
        int prod = 1, zero_count = 0;
        for(auto i : nums) {
            if(i == 0) {
                zero_count++;
                continue;
            }
            prod *= i;
        }
        
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) {
                if(zero_count == 1) {
                    nums[i] = prod;
                } else {
                    nums[i] = 0;
                }
            } else {
                if(zero_count) {
                    nums[i] = 0;
                } else {
                    nums[i] = prod / nums[i];
                }
            }
        }
        return nums;
    }
};