class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        int count = 0;
        for(char c : J) {
            jewels.insert(c);
        }

        for(char c : S) {
            if(jewels.find(c) != jewels.end())
                count++;
        }
        return count;
    }
};
