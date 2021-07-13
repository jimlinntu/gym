class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        assert(k >= 1); // otherwise, we cannot jump
        // dp[i] == the maximum score you can get at nums[i]
        vector<int> dp(n);
        // window.front().second is max({dp[i-j]}) where 1 <= j <= k
        deque<pair<int, int>> window;
        dp[0] = nums[0];
        window.push_back({0, dp[0]});
        // DP step:
        // dp[i] = nums[i] + max dp[i-j] where 1 <= j <= k
        for(int i = 1; i < n; i++){
            // pop out dated elements
            while(!window.empty() and window.front().first < i-k){
                window.pop_front();
            }
            dp[i] = nums[i] + window.front().second;
            // if an element's value is smaller than dp[i] and older
            // we will remove it
            while(!window.empty() and window.back().second < dp[i]){
                window.pop_back();
            }
            window.push_back({i, dp[i]});
        }
        return dp[n-1];
    }
};
