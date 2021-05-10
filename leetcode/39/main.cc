class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> ans;
    void solve(vector<int> &c, int sidx, int t){
        // sidx is avoid duplicates
        if(t == 0){
            ans.push_back(path);
            return;
        }
        if(t < 0) return; // no way to form the target sum
        for(int i = sidx; i < n; i++){
            path.push_back(c[i]);
            solve(c, i, t-c[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        solve(candidates, 0, target);
        return ans;
    }
};
