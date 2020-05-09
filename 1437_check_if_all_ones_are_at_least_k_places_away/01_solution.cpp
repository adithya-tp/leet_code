class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int f1 = 0, f2 = 0;
        while(f1 < nums.size() && nums[f1] != 1) {
            f1++;
            f2++;
        }
        int local_count = 0;
        f2++;
        while(f2 < nums.size()) {
            while(f2 < nums.size() && nums[f2] != 1) {
                local_count++;
                f2++;
            }
            if(local_count < k)
                if(f2 < nums.size())
                    return false;
            f1 = f2;
            f2++;
            local_count = 0;
        }
        return true;
    }
};
