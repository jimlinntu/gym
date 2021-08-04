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
        vector<int> dp(n);
        
        dp[0] = (t1[0] == t2[0]);
        for(int j = 1; j < n; j++){
            if(t1[0] == t2[j]) dp[j] = 1;
            else dp[j] = dp[j-1];
        }

        for(int i = 1; i < m; i++){
            // dp[i-1][j-1]
            int dp_i_1_j_1 = dp[0];
            if(t1[i] == t2[0]) dp[0] = 1;
            else dp[0] = dp[0];
            for(int j = 1; j < n; j++){
                int next_dp_i_1_j_1 = dp[j];
                if(t1[i] == t2[j]) dp[j] = dp_i_1_j_1+1;
                else dp[j] = max(dp[j-1], dp[j]);
                // dp[i-1][j-1]
                dp_i_1_j_1 = next_dp_i_1_j_1;
            }
        }
        return dp[n-1];
    }
};
