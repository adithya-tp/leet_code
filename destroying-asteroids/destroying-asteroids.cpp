class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        vector<long long> a;
        for(auto i : asteroids) {
            a.push_back(i);
        }
        
        sort(a.begin(), a.end());
        
        long long m = mass;
        for(auto i : a) {
            if(m >= i) {
                m += i;
            } else {
                return false;
            }
        }
        return true;
    }
};