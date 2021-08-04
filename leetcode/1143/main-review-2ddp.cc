class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        // .... d
        // .... d
        // dp[i][j] == max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1 if t1[i] == t2[j])
        // I think the reason that when t1[i] == t2[j], we must choose
        // dp[i-1][j-1] is because
        // dp[i-1][j] and dp[i-1][j-1] only have 1 character different
        // so dp[i-1][j] <= dp[i-1][j-1]+1(at most one character more)
        int m = t1.size(), n = t2.size();
        // dp[i][j] == the length of LCS between t1[0~i] and t2[0~j]
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = (t1[0] == t2[0]);
        for(int j = 1; j < n; j++){
            if(t1[0] == t2[j]) dp[0][j] = 1;
            else dp[0][j] = dp[0][j-1];
        }
        for(int i = 1; i < m; i++){
            if(t1[i] == t2[0]) dp[i][0] = 1;
            else dp[i][0] = dp[i-1][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(t1[i] == t2[j]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // throw t1[i] or t2[j] away
            }
        }
        return dp[m-1][n-1];
    }
};
