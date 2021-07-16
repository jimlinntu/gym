class Solution {
public:
    int get_len(string &s){
        int len = 0;
        for(int i = (int)s.size()-1; i >= 0;){
            len++;
            if(s[i] == '*') i -= 2;
            else i--;
        }
        return len;
    }

    int get_next(string &p, int i){
        // check .* or x*
        if(i+1 < p.size() and p[i+1] == '*') return i+2;
        return i+1;
    }

    bool isMatch(string s, string p) {
        int m = get_len(p); // logical characters (x* count as one)
        int n = s.size();
        // dp[i][j] == p[0]~p[i-1] match s[0]~s[j-1]
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // dp[0][0] == true
        dp[0][0] = true;
        // dp[0][j > 0] == false
        // dp[i > 0][0] == depends

        for(int i = 1, cur = 0, next; i <= m; i++, cur = next){
            // [0, i)
            next = get_next(p, cur);
            // has x*
            bool is_wild = (next-cur) == 2;
            // dp[i][0]: nonempty pattern matches an empty string
            if(is_wild) dp[i][0] = dp[i-1][0];
            else dp[i][0] = false;

            // [0, j)
            for(int j = 1; j <= n; j++){
                if(is_wild){
                    // Case 1: match it and step back
                    // Case 2: match it and do not step back
                    // Case 3: not match it
                    if(p[cur] == s[j-1] or p[cur] == '.')
                        dp[i][j] = dp[i-1][j-1] or dp[i][j-1] or dp[i-1][j]; 
                    else dp[i][j] = dp[i-1][j]; // not match
                }else{
                    // Case 1: match it and step back
                    // Case 2: not match it
                    if(p[cur] == s[j-1] or p[cur] == '.') dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = false;
                }
            }
        }
        return dp[m][n];
    }
};
