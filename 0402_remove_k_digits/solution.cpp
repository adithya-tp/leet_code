class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == k)
            return "0";
        stack<char> s;
        for(char c : num) {
            while(k && s.size() && (s.top() > c)) {
                s.pop();
                k--;
            }
            s.push(c);
        }
        while(k){
            s.pop();
            k--;
        }
        string res="";
        while(!s.empty()) {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
        
        return res;
    }
};
