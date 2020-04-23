class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> order_map(26);
        int lex = 1, limit,flag=0;
        for(char c : order) {
            order_map[c] = lex;
            lex++;
        }
        for(int i = 0; i < words.size() - 1; i++) {
            limit =  min(words[i].size(), words[i+1].size());
            for(int j = 0; j < limit; j++) {
                if(order_map[words[i][j]] > order_map[words[i+1][j]]) {
                    flag = 1;
                    break;
                }
                else if(order_map[words[i][j]] < order_map[words[i+1][j]])
                    break;
                else
                    if(j == limit - 1)
                        if(words[i].size() > limit)
                            flag = 1;
            }
            if(flag)
                break;
        }
        if(flag)
            return false;
        else
            return true;
    }
};