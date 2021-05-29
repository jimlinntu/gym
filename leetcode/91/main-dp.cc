class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(n == 0) return 0;
        // dp[i] == the number of decode ways in [0, i)
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = (int)(s[0] != '0'); // if it is 0, we have no way to decode it
        for(int i = 2; i <= n; i++){
            // One char
            if(s[i-1] != '0') dp[i] += dp[i-1];
            // Two chars
            int num = (s[i-2] - '0') * 10 + s[i-1] - '0';
            if(s[i-2] != '0' and 1 <= num and num <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
