class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int min = v.size();
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size() + 1; j++){
                vector<int> temp = v;
                vector<int> temp_cmp = v;
                vector<int> sub_array(v.begin() + i, v.begin() + j);
                int sub_array_size = sub_array.size();
                sort(sub_array.begin(), sub_array.end());
                copy(sub_array.begin(), sub_array.end(), temp.begin() + i);
                sort(temp_cmp.begin(), temp_cmp.end());
                if(v == temp_cmp)
                    return 0;
                if(temp == temp_cmp){
                    if(sub_array_size < min)
                        min = sub_array_size;
                }
            }
        }
        return min;
    }
};
