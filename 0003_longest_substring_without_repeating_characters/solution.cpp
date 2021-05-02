/*
    Solved using two pointers technique. 
    You build functions that add and remove elements to your 
    subarray / sliding window of interest. What they're actually
    doing is manipulating some data structure or variable that
    would be later used to check the goodness of the current window /
    subarray of elements. 

    Output the length of the longest good segment.
    Space complexity O(n) [hash map could potentially store all elements in a completely unique array (worst case)]
    Time complexity O(n) [every element visited once]
*/

class Solution {
public:
    unordered_map<int, int> m;
    int repeated_elems = 0;
    bool good() {
        return repeated_elems == 0;
    }
    
    void add(char c) {
        if(m[c] == 1) {
            repeated_elems++;
        }
        m[c]++;
    }
    
    void remove(char c) {
        if(m[c] == 2) repeated_elems--;
        m[c]--;
    }
    
    int lengthOfLongestSubstring(string s) {
        int left = 0, ans = 0;
        for(int right = 0; right < s.size(); right++) {
            add(s[right]);
            while(!good()) {
                remove(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};