class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> dp[501];
        dp[0] = {{}}; // an empty combination
        
        // O(n * target * (target / min(c))) (ignore dp[])
        for(int num: c){
            for(int w = target; w >= 0; w--){
                // Add it or not
                // 1. Not add it
                // no need to do this, but semantically, we should add
                // dp[w] = dp[w];
                vector<int> to_add;

                for(int i = 1; num * i <= w; i++){
                    // add i times of this `num`
                    to_add.push_back(num);

                    for(vector<int> &v: dp[w-i*num]){
                        dp[w].push_back(v);
                        dp[w].back().insert(dp[w].back().end(),
                              to_add.begin(), to_add.end());
                    }
                }
            }
        }
        return dp[target];
    }
};
