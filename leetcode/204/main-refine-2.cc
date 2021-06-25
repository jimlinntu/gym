using LL = long long int;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        int count = 0;
        for(int i = 2; i < n; i++){
            if(!isprime[i]) continue;
            count++;
            // mark everything that is the multiple of this prime as false
            for(int j = i; ((LL)i * j) < (LL)n; j++){
                isprime[i*j] = false;
            }
        }
        return count;
    }
};
