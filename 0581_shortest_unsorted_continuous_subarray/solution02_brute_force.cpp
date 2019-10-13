class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int r = 0, l = v.size();
        for(int i = 0; i < v.size() - 1; i++){
            for(int j = i + 1; j < v.size(); j++){
                if(v[j] < v[i]){
                    r = max(j, r);
                    l = min(i, l);
                }
            }
        }
        return (r - l) < 0 ? 0 : r - l + 1;
    }
};
