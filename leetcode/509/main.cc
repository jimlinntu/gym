class Solution {
public:
    int fib(int n) {
        int pp = 0, p = 1;
        if(n == 0) return 0;
        if(n == 1) return 1;
        for(int i = 2; i <= n; i++){
            int num = p + pp;
            // rotate
            pp = p;
            p = num;
        }
        return p;
    }
};
