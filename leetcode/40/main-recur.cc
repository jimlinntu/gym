class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> ans;
    // O(2^n) at worst
    void solve(vector<int> &candidates, int t, int i, bool chosen){
        if(t == 0){
            ans.push_back(path);
            return;
        }
        // No way to complete the sum
        if(t < 0) return;
        if(i >= n){
            return;
        }

        // Choose it or not
        if(i == 0 or (candidates[i-1] != candidates[i] or chosen)){
            // If this is a duplicate numbers
            // We only conisder
            // TTTF
            // TTFF
            // TFFF
            // FFFF
            path.push_back(candidates[i]);
            solve(candidates, t - candidates[i], i+1, true);
            path.pop_back();
        }
        solve(candidates, t, i+1, false);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        assert(target > 0);
        solve(candidates, target, 0, true);
        return ans;
    }
};
