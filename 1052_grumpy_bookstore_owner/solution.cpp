class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int extra_points = 0, fo_sure = 0, curr_max = 0;
        // find the number of customers we'll get for sure, without having to pull off the "X - minute" trick
        for(int i = 0; i < customers.size(); i++){
            if(grumpy[i] == 0){
                fo_sure += customers[i];
            }
        }

        // "initializing" the sliding window
        for(int i = 0; i < X; i++){
            if(grumpy[i] == 1){
                extra_points += customers[i];
            }
        }

        curr_max = max(fo_sure + extra_points, curr_max);
        // run "rolling window" to keep track of max
        for(int i = X; i < customers.size(); i++){
            //shrink
            if(grumpy[i - X] == 1){
                extra_points -= customers[i - X];
            }
            //expand
            if(grumpy[i] == 1){
                extra_points += customers[i];
            }
            // check if fo_sure with the next extra_points is bigger than the current_max
            curr_max = max(fo_sure + extra_points, curr_max);
        }
        return curr_max;
    }
};
