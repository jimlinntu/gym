class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        int num_prime = 0;
        for(int i = 2; i < n; i++){
            if(isprime[i]) num_prime++;
            // Cross out the multiple of i
            for(int j = 2*i; j < n; j += i){
                isprime[j] = false;
            }
        }
        return num_prime;
    }
};
