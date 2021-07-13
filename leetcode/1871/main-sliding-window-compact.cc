class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        // A compact version of a sliding window
        // # reachable positions within the current window
        // from [i-maxJump, i-minJump]
        int window = 0;
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < n; i++){
            // Remove the leftmost i-maxJump-1 element from the window
            if(i-maxJump-1 >= 0 and dp[i-maxJump-1]) window--;
            // Add i-minJump to the window
            if(i-minJump >= 0 and dp[i-minJump]) window++;
            
            // if [i-maxJump, i-minJump] contains at least one reachable
            // dp[i] will be reachable!
            dp[i] = window > 0 and s[i] == '0';
        }
        return dp[n-1];
    }
};
