class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    void solve(int startidx, int k){
        if(k == 0){
            ans.push_back(path);
            return;
        }
        if(startidx > n) return;
        for(int i = startidx; i <= n; i++){
            path.push_back(i);
            // we have use one
            solve(i+1, k-1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        solve(1, k);
        return ans;
    }
};
