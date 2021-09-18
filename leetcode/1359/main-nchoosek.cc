using LL = long long int;
class Solution {
public:
    LL C(int n, int k){
        // O(k)
        if(k > n-k){
            k = n-k;
        }
        LL res = 1;
        // NOTE: the beautiful part of this O(k) algorithm
        // is it ensure this number is an integer!
        for(int i = 0; i < k; i++){
            res *= (n-i);
            res /= (i+1);
        }
        // res = n*(n-1) ...  / [(k) * (k-1) ... 1]
        return res;
    }
    int countOrders(int n) {
        int N = 2*n;
        
        LL ans = 1;
        for(int i = 0; i < N; i += 2){
            ans = (ans * C(N-i, 2)) % (1000000007);
        }
        return ans;
    }
};
