class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;
        unordered_map<int, int> rev_count;
        for(int i : arr){
            count[i] += 1;
        }
        for(auto i : count){
            if(rev_count.find(i.second) == rev_count.end()){
                rev_count[i.second] = i.first;
            }
            else
                return false;
        }
        return true;
    }
};
