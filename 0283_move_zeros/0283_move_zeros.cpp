class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int non_zero_index = 0;
        for(int i = 0; i < v.size(); i++){
            if(v[i]){
                v[non_zero_index] = v[i];
                non_zero_index++;   
            }
        }
        while(non_zero_index < v.size()){
            v[non_zero_index] = 0;
            non_zero_index++;
        }
    }
};
