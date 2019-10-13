class Solution {
public:
    int singleNumber(vector<int>& v) {
        unordered_map<int, int> counts;
        for(int i=0; i < v.size(); i++){
            counts[v[i]]++;
        }
        for(int i : v){
            if(counts[i] == 1){
                return i;
            }
        }
        return 0;
    }
};
