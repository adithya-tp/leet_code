class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag_count;
        unordered_map<char, int> ran_count;
        for(char c : magazine) {
            mag_count[c]++;
        }
        for(char c : ransomNote) {
            ran_count[c]++;
        }
        for(auto c : ran_count) {
            if(ran_count[c.first] > mag_count[c.first]) {
                return false;
            }
        }
        return true;
    }
};
