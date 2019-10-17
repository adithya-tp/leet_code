class Solution {
public:
    int trap(vector<int>& towers) {
        vector<int> leftMax, rightMax;
        int num_towers = towers.size();
        if(num_towers == 0)
            return 0;
        int max_left = 0;
        int max_right = 0;
        for(int i = 0; i < num_towers; i++){
            max_left = max(towers[i], max_left);
            leftMax.push_back(max_left);
            max_right = max(towers[num_towers - i - 1], max_right);
            rightMax.push_back(max_right);
        }

        int water = 0;
        int curr_height;
        for(int i = 0; i < num_towers; i++){
            curr_height = towers[i];
            water += max(min(leftMax[i], rightMax[num_towers - i - 1]) - curr_height, 0);
        }
        return water;
    }
};
