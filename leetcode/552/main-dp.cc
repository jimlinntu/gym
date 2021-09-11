#define MOD (1000000007LL)

using LL = long long int;
enum Type {A = 0, L = 1, P = 2};

class Solution {
public:
    int checkRecord(int n) {
        // dp[i][type]: the number of possible combinations ending at type
        vector<vector<LL>> dp(n, vector<LL>(3, 0));
        // dp_noA[i][type]: same definition but with no A within it
        // (so type == L or P)
        vector<vector<LL>> dp_noA(n, vector<LL>(3, 0));
        // Put A, L, P
        dp[0][A] = dp[0][L] = dp[0][P] = 1;
        // Put L, P
        dp_noA[0][L] = dp_noA[0][P] = 1;
        for(int i = 1; i < n; i++){
            dp[i][P] = (dp[i-1][A] + dp[i-1][L] + dp[i-1][P]) % MOD;
            
            // L or LL
            dp[i][L] = (dp[i-1][A] + dp[i-1][P]) % MOD;
            dp[i][L] += ((i >= 2)? (dp[i-2][A] + dp[i-2][P]):(1)) % MOD;
            

            dp[i][A] = (dp_noA[i-1][L] + dp_noA[i-1][P]) % MOD;
            
            // dp_noA recursion
            // L or LL
            dp_noA[i][L] = (dp_noA[i-1][P] + ((i >= 2)?(dp_noA[i-2][P]):(1))) % MOD;

            dp_noA[i][P] = (dp_noA[i-1][P] + dp_noA[i-1][L]) % MOD;
        }
        return (dp[n-1][A] + dp[n-1][L] + dp[n-1][P]) % MOD;
    }
};
