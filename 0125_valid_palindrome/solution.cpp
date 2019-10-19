class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> s_vec;
        for(char c : s){
            if(isalnum(c)){
                s_vec.push_back(tolower(c));
            }
        }
        int len = s_vec.size();
        for(int i = 0; i < len / 2; i++){
            if(s_vec[i] != s_vec[len - i - 1])
                return false;
        }
        return true;
    }
};
