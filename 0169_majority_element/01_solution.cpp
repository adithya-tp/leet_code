class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count_map;
        int ans;
        for(int i = 0; i < nums.size(); i++) {
            count_map[nums[i]]++;
            if(count_map[nums[i]] > (nums.size() / 2)) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};
