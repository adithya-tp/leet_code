class Solution {
public:
    vector<int> source_freq, target_freq;
    int window_count, target_count;
    Solution() {
        source_freq.resize(128, 0);
        target_freq.resize(128, 0);
        window_count = 0;
        target_count = 0;
    }
    
    void add_element(int val) {
        if(++source_freq[val] == target_freq[val]) {
            window_count++;
        }
    }
    
    void remove_element(int val) {
        if(source_freq[val]-- == target_freq[val]) {
            window_count--;
        }
    }
    
    bool good() {
        return window_count == target_count;
    }
    
    vector<int> findAnagrams(string s, string t) {
        for(char c : t) {
            target_freq[c - 'A']++;
        }
        
        for(int i = 0; i < target_freq.size(); i++) {
            if(target_freq[i] > 0) target_count++;
        }
        
        int start = 0;
        vector<int> ans;
        // A string is an anagram if the window has both reached all goals
        // and has the same length as the target string
        for(int end = 0; end < s.size(); end++) {
            add_element(s[end] - 'A');
            while(good()) {
                if(end - start + 1 == t.size()) {
                    ans.push_back(start);
                }
                remove_element(s[start++] - 'A');
            }
        }
        return ans;
    }
};