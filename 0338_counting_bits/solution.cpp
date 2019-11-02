class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bit_count(num+1, 0);
        int n, unset_index;
        for(int i = 1; i <= num; i++){
            n = ~(i-1);
            unset_index = log2(n & -n) + 1;
            if(unset_index == log2(i) + 1)
                bit_count[i] = 1;
            else
                bit_count[i] = bit_count[i-1] - (unset_index - 1) + 1;
        }
        return bit_count;
    }
};
