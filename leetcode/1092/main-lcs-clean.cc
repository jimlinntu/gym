class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        // dp[i][j] == s1[0, i) and s2[0, j)
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        // dp[0][0] = 0
        // dp[i > 0][0] and dp[0][j > 0] are also 0
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        string ans(m+n-dp[m][n], 0);
        // Backtracking
        int ans_idx = (int)ans.length()-1;
        int p1 = m, p2 = n;
        while(p1 > 0 and p2 > 0){
            if(s1[p1-1] == s2[p2-1]){
                // match
                ans[ans_idx--] = s1[p1-1];
                p1--, p2--;
            }else if(dp[p1-1][p2] >= dp[p1][p2-1]){
                ans[ans_idx--] = s1[p1-1];
                // delete s1[p1-1] means this character will appear in superseq
                p1--;
            }else{
                ans[ans_idx--] = s2[p2-1];
                p2--;
            }
        }
        // add the remaining
        while(p1 > 0) ans[ans_idx--] = s1[--p1];
        while(p2 > 0) ans[ans_idx--] = s2[--p2];

        return ans;
    }
};
