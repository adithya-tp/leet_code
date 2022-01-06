class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        stringstream ss;
        int len = s.size(), biggest_step = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++) {
            int step = (i == numRows - 1 || i == 0) ? biggest_step : 2 * i;
            for(int j = i; j < len; j += step) { 
                ss << s[j];
                if (i > 0 && i < numRows - 1) {
                    step = biggest_step - step;
                }
            }
        }
        return ss.str();
    }
};