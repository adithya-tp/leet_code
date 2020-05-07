class Solution {
public:
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int idx = 0, pos = 0;
        unordered_map<char, int> char_index_map;
        unordered_map<int, int> idx_pos_map;
        vector<int> counts(s.size());
        for(char c : s) {
            if(char_index_map.find(c) == char_index_map.end()) {
                char_index_map[c] = idx;
                idx_pos_map[idx] = pos;
                counts[idx]++;
                idx++;
            }
            else {
                counts[char_index_map[c]]++;
            }
            pos++;
        }
        for(int i = 0; i < counts.size(); i++) {
            if(counts[i] ==  1)
                return idx_pos_map[i];
        }
        return -1;
    }
};
