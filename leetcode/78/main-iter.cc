class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = {{}};
        // A iterative (kind of like dynamic programming)
        for(int i = 0; i < n; i++){
            // At the start of the loop
            // ans == the power set of nums from 0 ~ i-1
            int ans_n = ans.size();
            for(int j = 0; j < ans_n; j++){
                // ans from 0 ~ ans_n-1 will be seen as NOT adding nums[i]
                // ans from ans_n ~ 2*ans_n-1 will be seen as adding nums[i]
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]); // adding nums[i]
            }
            // At the end of the loop
            // ans == the power set of nums from 0 ~ i
        }
        return ans;
    }
};
