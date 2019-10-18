class Solution {
public:
    int fib(int N) {
        int fib;
        int a = 0;
        int b = 1;
        for(int i = 2; i < N + 1; i++){
            fib = a + b;
            a = b;
            b = fib;
        }
        return (N == 0 || N == 1) ? N : fib;
    }
};
