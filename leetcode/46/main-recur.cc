class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int startidx){
        if(startidx >= n){
            ans.push_back(nums);
            return;
        }
        for(int i = startidx; i < n; i++){
            // Every num can be at startidx!
            swap(nums[startidx], nums[i]);
            solve(nums, startidx+1);
            swap(nums[startidx], nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        solve(nums, 0);
        return ans;
    }
};
