class Solution {
public:
    int integerBreak(int n) {
        // dp[i] == the maximum product i can achieve (including itself i)
        vector<int> dp(n);
        dp[1] = 1;
        for(int i = 2; i < n; i++){
            dp[i] = i; // at least itself
            for(int num = 1; num < i; num++){
                dp[i] = max(dp[i], num*dp[i-num]);
            }
        }
        // NOTE: dp_n does not contain itself!!
        int dp_n = INT_MIN;
        for(int num = 1; num < n; num++){
            dp_n = max(dp_n, num * dp[n-num]);
        }
        return dp_n;
    }
};
