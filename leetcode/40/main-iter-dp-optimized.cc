class Solution {
public:
    int n;
    void concat(vector<int> &v, vector<int> &v2){
        v.insert(v.end(), v2.begin(), v2.end());
    }
    void p(vector<int> &v){
        for(int e: v) cout << e << " ";
        cout << "\n";
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        if(n == 0) return {};
        sort(candidates.begin(), candidates.end());
        // dp[i, t] == the combination of candidates[0]~[i] that can achieve t
        // dp[i, t] == add candidates[i] or not
        //          == { dp[i-1, t-candidates[i]] add candidates[i] +
        //               dp[i-1, t] }
        vector<vector<int>> dp[31]; // Optimized version

        for(int i = 0, j; i < n; i = j){
            for(j = i; j < n and candidates[i] == candidates[j]; j++){}
            // [i, j) contains the same numbers
            int num = candidates[i];
            int count = j-i;

            if(i > 0){
                // dp[k] will not be used after k--
                for(int k = target; k >= 0; k--){
                    vector<int> v;
                    // Try adding 0, 1, ... j-i of this numbers
                    vector<vector<int>> dp_k;
                    for(int l = 0; l <= count; l++){
                        // no need to search
                        // == 0 is crucial to avoid infinite loop
                        if(k - l * num < 0) break;
                        for(vector<int> comb: dp[k - l * num]){
                            concat(comb, v);
                            // dp k can be formed
                            // by dp[k-l*num] combination concatenated by v
                            // NOTE: dp_k cannot be dp[k]!!
                            // because dp[k] already has some content inside!!!!
                            dp_k.push_back(comb);
                        }
                        v.push_back(num);
                    }
                    dp[k] = dp_k;
                }
            }else{
                vector<int> v;
                // Try adding 0, 1, ... j-i of this numbers
                for(int k = 0; k <= count; k++){
                    if(k * num > target) break;
                    dp[k * num].push_back(v);
                    v.push_back(num);
                }
            }
        }
        return dp[target];
    }
};
