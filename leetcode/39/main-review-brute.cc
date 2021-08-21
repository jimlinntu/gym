class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void solve(vector<int> &c, int start, int target){
        // choose c[start] or not
        if(start >= c.size()){
            if(target == 0) ans.push_back(path);
            return;
        }
        int num = c[start];
        // Not to select
        solve(c, start+1, target);
        // Select
        int n = path.size();
        for(int i = 1; i * num <= target; i++){
            path.push_back(num);
            solve(c, start+1, target-i*num);
        }
        path.resize(n);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        solve(c, 0, target);
        return ans;
    }
};
