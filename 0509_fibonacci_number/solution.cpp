class Solution {
public:
    int fib(int N) {
        int fib_new;
        vector<int> fibs = {0, 1};
        for(int i = 2; i < N + 1; i++){
            fib_new = fibs[i - 1] + fibs[i - 2];
            fibs.push_back(fib_new);
        }
        return fibs[N];
    }
};
