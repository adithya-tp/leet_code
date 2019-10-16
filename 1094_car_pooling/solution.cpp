class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int total = 0;
        vector<pair<int, int>> make_number_line;
        for(auto it = trips.begin(); it != trips.end(); it++){
            make_number_line.push_back(make_pair((*it)[1], (*it)[0]));
            make_number_line.push_back(make_pair((*it)[2], -(*it)[0]));
        }
        sort(make_number_line.begin(), make_number_line.end());

        for(auto i : make_number_line){
            total += i.second;
            if(total > capacity)
                return false;
        }
        return true;
    }
};
