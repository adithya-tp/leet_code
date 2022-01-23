class Solution {
public:
    void search_seq(vector<int>& ans, long curr_num, int l, int h) {
        if (curr_num > h) {
            return;
        }
        
        if (curr_num >= l) {
            ans.push_back(curr_num);
        }
        int dig = curr_num % 10;
        if(dig == 9) return;
        search_seq(ans, curr_num * 10 + dig + 1, l, h);
    }
    
    
    vector<int> sequentialDigits(int low, int high) {
        int num_digits = ceil(log10(low));
        int msd = low / pow(10, num_digits - 1);
        vector<int> ans;
        for(int i = 1; i < 10; i++) {
            int seed_num = i;
            for(int l = 0; l < num_digits - 1; l++) {
                if (seed_num % 10 == 9) break;
                seed_num = 1 + (seed_num % 10) + (seed_num * 10);
            }
            search_seq(ans, seed_num, low, high);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};