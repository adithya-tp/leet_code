class Solution {
public:
    bool isSelfDiv(int num) {
        int temp = num;
        while(temp) {
            int dig = temp % 10;
            if(dig == 0 || num % dig != 0)
                return false;
            temp /= 10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> out;
        for(int i = left; i <= right; i++) {
            if(isSelfDiv(i))
                out.push_back(i);
        }
        return out;
    }
};
