class Solution {
public:
    int findComplement(int num) {
        int digs=log2(num);
        int one = 1;
        for(int i = 0; i <= digs; i++) {
            num ^= one;
            one <<= 1;
        }
        return num;
    }
};
