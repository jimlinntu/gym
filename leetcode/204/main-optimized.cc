class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        int num_prime = 0;
        bool done = false;
        for(int i = 2; i < n; i++){
            if(isprime[i]) num_prime++;
            else continue; // Skip this number because its multiple has already be marked!
            if(done) continue; // this is to gaurd i * i overflow issue
            if(i*i >= n) done = true;
            // Cross out the multiple of i
            for(int j = i*i; j < n; j += i){
                isprime[j] = false;
            }
        }
        return num_prime;
    }
};
