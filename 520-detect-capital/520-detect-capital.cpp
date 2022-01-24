class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper_count = 0, len = word.size();
        bool first_upper = false;
        for(int i = 0; i < len; i++) {
            if (isupper(word[i])) {
                if (i == 0) first_upper = true;
                upper_count++;
            }
        }
        return (upper_count == len) || (first_upper && upper_count == 1) || (upper_count == 0);
    }
};