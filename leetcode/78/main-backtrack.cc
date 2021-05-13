class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, int i){
        if(i >= n){
            ans.push_back(path);
            return;
        }
        // Not to choose
        backtrack(nums, i+1);
        // To choose
        path.push_back(nums[i]);
        backtrack(nums, i+1);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        backtrack(nums, 0);
        return ans;
    }
};
