class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int> dp(n+1);
        // s1: [0, 0) vs s2: [0, j)
        dp[0] = 0;
        for(int j = 1; j <= n; j++){
            dp[j] = dp[j-1] + (int)s2[j-1];
        }
        // s1: [0, i) vs s2: [0, j)
        int prev, ds1, ds2;
        for(int i = 1; i <= m; i++){
            prev = dp[0];
            dp[0] = dp[0] + (int)s1[i-1]; // s1: [0, i) vs s2: [0, 0)
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]){
                    swap(dp[j], prev);
                }else{
                    // delete s1[i-1]
                    ds1 = dp[j] + (int)s1[i-1];
                    // delete s2[j-1]
                    ds2 = dp[j-1] + (int)s2[j-1];
                    prev = dp[j];
                    dp[j] = min(ds1, ds2);
                }
            }
        }
        return dp[n];
    }
};
