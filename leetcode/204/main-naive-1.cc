class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        int count = 0;
        for(int i = 2; i < n; i++){
            if(!isprime[i]) continue;
            count++;
            // mark everything that is the multiple of this prime as false
            for(int j = 2; i * j < n; j++){
                isprime[i*j] = false;
            }
        }
        return count;
    }
};
