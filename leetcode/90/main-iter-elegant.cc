class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = {{}};
        // Sort them so that duplicates will be consecutive
        sort(nums.begin(), nums.end());

        int prev_pset_n = ans.size();
        for(int i = 0; i < n; i++){
            // At the start of loop,
            // ans is the power set of nums from 0~i-1
            int startidx = 0;
            int pset_n = ans.size();
            // This condition is handle this case:
            // Ex. [1, 2, 3, 3]
            // The power set of [1, 2] is:
            // {[], [1], [2], [1, 2]}
            // When we make a DP step on [1, 2, 3] (i.e. [1, 2] + [3])
            // It will be like:
            // {[], [1], [2], [1, 2]} + {[3], [1, 3], [2, 3], [1, 2, 3]}
            //      (not to add 3)    +           (to add 3)
            // However, when we make a DP step on [1, 2, 3, 3] (i.e. [1, 2, 3] + [3])
            // We should avoid considering: {[], [1], [2], [1, 2]}
            // Because it will generate duplicates!
            // In another perspective:
            // For [3, 3], we only want these selections: FF, TF, TT (not FT)
            if(i >= 1 and nums[i-1] == nums[i]) startidx = prev_pset_n;
            prev_pset_n = pset_n;
            for(int j = startidx; j < pset_n; j++){
                ans.push_back(ans[j]);
                // Add nums[i]
                ans.back().push_back(nums[i]);
            }
            // After the loop, ans is the power set of nums from 0~i
        }
        return ans;
    }
};
