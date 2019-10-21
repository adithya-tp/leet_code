class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int mountain = 0;
        int flag = 0;
        if(A.size() < 3)
            return false;
        for(int i = 0; i < A.size() - 1; i++){
            if(flag == 0){
                if(A[i+1] > A[i]){         
                    continue;
                }   
                else{
                    flag = 1;
                    if(i == 0)
                        return false;
                }
            }   
            if(flag == 1){
                if(A[i+1] < A[i])
                    continue;
                else
                    return false;
            }
        }   
        if(flag == 0)
            return false;
        else
            return true;
    }
};
