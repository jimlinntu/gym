class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // dp[i] == whether position i is reachable from 0
        // dp[i] == OR(dp[i-j]) where minJump <= j <= maxJump
        int n = s.length();
        deque<pair<int, bool>> window;
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < n; i++){
            // pop outdated
            while(!window.empty() and window.front().first < i-maxJump){
                window.pop_front();
            }
            if(i-minJump >= 0){
                while(!window.empty() and window.back().second < dp[i-minJump]){
                    window.pop_back();
                }
                // add dp[i-minJump]
                window.push_back({i-minJump, dp[i-minJump]});
            }

            dp[i] = !window.empty() and window.front().second and s[i] == '0';
        }
        return dp[n-1];
    }
};
