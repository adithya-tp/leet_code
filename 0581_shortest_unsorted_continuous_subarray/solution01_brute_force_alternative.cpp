class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        int min = v.size();
        int v_size = v.size();
        int max_unsorted1, min_subarray, max_subarray, min_unsorted2;
        if(is_sorted(v.begin(), v.end()))
            return 0;
        for(int i = 0; i < v.size(); i++){
            for(int j = i + 1; j < v.size() + 1; j++){
                 vector<int> temp = v;
                vector<int> sub_array(temp.begin() + i, temp.begin() + j);
                int unsorted1_size = i, unsorted2_size = v_size - j;
                sort(temp.begin(), temp.begin() + i);
                sort(temp.begin() + j, temp.end());
                sort(sub_array.begin(), sub_array.end());
                max_unsorted1 = (unsorted1_size == 0) ? 0 : temp[i - 1];
                min_subarray = sub_array[0];
                max_subarray = sub_array[sub_array.size() - 1];
                min_unsorted2 = (unsorted2_size == 0) ? max_subarray : temp[j];
                if((max_unsorted1 <= min_subarray) && (max_subarray <= min_unsorted2) && is_sorted(v.begin(), v.begin() + i) && is_sorted(v.begin() + j, v.end())){
                    if(sub_array.size() < min)
                        min = sub_array.size();
                }
            }        
        }
        return min;
    }
};
