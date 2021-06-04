class Solution {
public:
    int n;
    void p(vector<int> &v){
        for(int e: v) cout << e << " ";
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        if(n == 0) return {};
        sort(candidates.begin(), candidates.end());
        // dp[i, t] == the combination of candidates[0]~[i] that can achieve t
        // dp[i, t] == add candidates[i] or not
        //          == { dp[i-1, t-candidates[i]] add candidates[i] +
        //               dp[i-1, t] }
       vector<vector<int>> dp[100][31];

        for(int i = 0, j; i < n; i = j){
            for(j = i; j < n and candidates[i] == candidates[j]; j++){}
            // [i, j) contains the same numbers
            vector<int> v;
            if(i > 0){
                // Try adding 0, 1, ... j-i of this numbers
                for(int l = 0; l <= (j-i); l++){
                    for(int k = 0; k <= target; k++){
                        if(k - l * candidates[i] < 0) continue;
                        // Loop over each combination that forms
                        // k - l * candidates[i]
                        // for each combination, add l of this numbers
                        for(vector<int> comb: dp[i-1][k - l * candidates[i]]){
                            // Add l of this numbers
                            comb.insert(comb.end(), v.begin(), v.end());
                            // dp[j-1][k] can be formed by
                            // adding l candidates[i]
                            dp[j-1][k].push_back(comb);
                        }
                    }
                    v.push_back(candidates[i]);
                }
            }else{
                // Try adding 0, 1, ... j-i of this numbers
                for(int k = 0; k <= (j-i); k++){
                    if(k * candidates[i] > target) break;
                    dp[j-1][k * candidates[i]].push_back(v);
                    v.push_back(candidates[i]);
                }
            }
        }
        return dp[n-1][target];
    }
};
