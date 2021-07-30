class Solution {
public:
    int numWays(int n, int k) {
        // dp[i] == the # of ways from 0~i
        vector<int> dp(n);
        dp[0] = k; // k colors from we can choose
        if(n >= 2)
            dp[1] = k + k * (k-1); // same or different
        for(int i = 2; i < n; i++){
            // Case 1: Choose a color different from the last one before
            // Case 2: Choose a color same as the last one <--- hard
            // The reason why Case 2 == dp[i-2] * (k-2) is
            // If we directly set dp[i-1] * 1, this may cause this case
            // a b c c | c
            // In order to avoid that, we go one step before
            // * * * j j
            // Then the only thing we need to do is to set j different the last number
            // from dp[i-2] ==> dp[i-2] * (k-1) (because j only has to differ from the last)
            dp[i] = dp[i-1] * (k-1) + dp[i-2] * (k-1);
        }
        return dp[n-1];
    }
};
