class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        // Complexity: O(n^2) using dynamic programming
        // dp[i][j] == whether s[i~j] is a palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int ans = 0;
        // dp[i][i] == true
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            ans++;
        }
        // dp[i][j] == (s[i] == s[j]) and dp[i+1][j-1]
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) and ((i+1 <= j-1)? (dp[i+1][j-1]): (true));
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
