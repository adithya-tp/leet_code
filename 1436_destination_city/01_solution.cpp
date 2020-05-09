class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> route_map;
        for(int i = 0; i < paths.size(); i++) {
            route_map[paths[i][0]] = paths[i][1];
        }
        auto i = route_map[paths[0][0]];
        while(route_map.find(i) != route_map.end()) {
            i = route_map[i];
        }
        return i;
    }
};
