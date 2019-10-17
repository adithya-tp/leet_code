class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int total = 0;
        for(auto c : s){
            if(c == 'R')
                count += 1;
            else
                count -= 1;
            if(count == 0)
                total += 1;
        }
        return total;
    }
};
