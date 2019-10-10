class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for(int i = 0; i < (size / 2); i++){
            int rev_index = size - i - 1;
            char c = s[rev_index];
            s[rev_index] = s[i];
            s[i] = c;
        }
    }
};
