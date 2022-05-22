class Solution {
public:
    int percentageLetter(string s, char letter) {
        vector<double> c(26, 0);
        for(char ch : s) {
            c[ch - 'a']++;
        }
        return floor(c[letter - 'a'] / s.size() * 100);
    }
};