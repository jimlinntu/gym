class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> ans;
    // Complexity: O(n * 2^n) at worst
    void backtrack(vector<int> &nums, int i){
        if(i >= n){
            ans.push_back(path);
            return;
        }
        int j = i;
        for(; j < n; j++) if(nums[j] != nums[i]) break;
        // [i, j) is a duplicate region
        // Ex. [x, x, x ... x] having k == j-i numbers can only produce
        // [], [x], [x, x], ... [x, x, x... x]: k+1 subsets
        for(int len = 0; len <= (j-i); len++){
            backtrack(nums, j);
            path.push_back(nums[i]);
        }
        // Restore path
        for(int len = 0; len <= (j-i); len++){
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        backtrack(nums, 0);
        return ans;
    }
};
