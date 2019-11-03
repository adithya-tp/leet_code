class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int count = 0, s = arr.size();
        int left, right, temp;
        vector<int> arr2 = arr;
        while(true){
            for(int i = 1; i < arr.size() - 1; i++){
                left = arr[i-1];
                right = arr[i+1];
                temp = arr[i];
                if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
                    temp = arr[i]-1;
                }
                else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]){
                    temp = arr[i]+1;
                }
                else{
                    count++;
                }
                arr2[i] = temp;
                if(count == s - 2)
                    return arr;
            }
            arr = arr2;
            count = 0;
        }
        return arr;
    }
};

