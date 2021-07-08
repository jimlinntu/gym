class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

        // Base case: t[n-1]~t[n-1]
        for(int i = m-1; i >= 0; i--){
            if(s[i] == t[n-1]) dp[i][n-1] = i;
            else if(i < m-1) dp[i][n-1] = dp[i+1][n-1];
            else dp[i][n-1] = INT_MAX; // impossible
        }
        // dp[i][j] =
        // if s[i] == t[j]: dp[i+1][j+1]
        // else dp[i+1][j]
        for(int i = m-2; i >= 0; i--){
            for(int j = n-2; j >= 0; j--){
                if(s[i] == t[j]) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = dp[i+1][j];
            }
        }

        int best_i = -1;
        int min_len = INT_MAX;
        for(int i = 0; i < m; i++){
            int idx = dp[i][0];
            if(idx == INT_MAX) continue;
            if(idx - i + 1 < min_len){
                min_len = idx-i+1;
                best_i = i;
            }
        }
        if(best_i == -1) return "";
        return s.substr(best_i, min_len);
    }
};
