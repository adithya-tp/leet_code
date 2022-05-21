class NumArray {
public:
    int size;
    vector<int> st;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        size = 1;
        while(size < n) {
            size *= 2;
        }
        st.resize(2 * size, 0);
        
        for(int i = 0; i < n; i++) {
            update(i, nums[i]);
        }
    }
    
    void _update(int arr_idx, int val, int seg_idx, int seg_left, int seg_right) {
        if(seg_right - seg_left == 1) {
            st[seg_idx] = val;
            return;
        }
        
        int mid = seg_left + (seg_right - seg_left) / 2;
        if (arr_idx < mid) {
            _update(arr_idx, val, 2 * seg_idx + 1, seg_left, mid);
        } else {
            _update(arr_idx, val, 2 * seg_idx + 2, mid, seg_right);
        }
        st[seg_idx] = st[2 * seg_idx + 1] + st[2 * seg_idx + 2];
    }
    
    void update(int index, int val) {
        // cout << "Updating...\n";
        _update(index, val, 0, 0, size);
        // for(int i : st) {
        //     cout << i << " ";
        // }
        // cout << "\n";
    }
    
    int _get(int arr_left, int arr_right, int seg_idx, int seg_left, int seg_right) {
        if (seg_left >= arr_right || seg_right <= arr_left) {
            return 0;
        } else if (seg_left >= arr_left && seg_right <= arr_right) {
            return st[seg_idx];
        } else {
            int mid = seg_left + (seg_right - seg_left) / 2;
            return _get(arr_left, arr_right, 2 * seg_idx + 1, seg_left, mid) + _get(arr_left, arr_right, 2 * seg_idx + 2, mid, seg_right);
        }
    }
    
    int sumRange(int left, int right) {
        return _get(left, right + 1, 0, 0, size);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */