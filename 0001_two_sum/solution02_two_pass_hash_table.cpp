class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> n2i;
        vector<int> idxs;
        for(int i = 0; i < nums.size(); i++){
            n2i[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int num2 = target - nums[i];
            if(n2i.find(num2) != n2i.end()){
                int ind2 = n2i.at(num2);
                if(i != ind2){
                    idxs.push_back(i);
                    idxs.push_back(ind2);
                    return idxs;
                }
            }
        }
        return idxs;
    }
};
