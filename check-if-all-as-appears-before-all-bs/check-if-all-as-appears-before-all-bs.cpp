class Solution {
public:
    bool checkString(string s) {
        bool a_before_b = true, seen_b = false;
        int len = s.size();
        for(int i = 0; i < len; i++) {
            if(s[i] == 'b') {
                seen_b = true;
            } else {
                if(seen_b) {
                    return false;
                }
            }
        }
        return a_before_b;
    }
};