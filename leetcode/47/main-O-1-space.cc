class Solution {
public:
    int n;
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int startidx){
        if(startidx >= n){
            ans.push_back(nums);
            return;
        }
        // Every element can be placed at startidx
        for(int i = startidx; i < n; i++){
            // Same numbers will ALWAYS be concecutive in this [startidx, n) region
            // because we have sorted
            // See the proof I have provided in the same folder

            // If nums[i] is equal to the previous placed value
            // we will skip it due to duplicate cases
            if(i != startidx and nums[i] == nums[startidx]) continue;
            swap(nums[startidx], nums[i]);
            solve(nums, startidx+1);
            // NOTE: We DON'T have to swap it back!
            //       This is because we want to preserve the consecutive property
            //       in [startidx+1, n)
        }
        // Restore its original order
        for(int i = n-1; i >= startidx; i--){
            if(nums[startidx] != nums[i]) swap(nums[startidx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        // The crucial part!!!
        // Ex. [1, 2, 2, 3] vs [1, 2, 3, 2]
        // [1, 2, 2, 3] ->
        // 1. [1*, 2, 2, 3], 2. [2*, 1, 2, 3]
        // 3. [2*, 2, 1, 3], 4. [3*, 2, 2, 1]
        // Note that because the array is sorted,
        // (2.) and (3.) are the same. In this case, we will want to eliminate (3.)

        // Proof: detailed proof is the pdf file in this folder
        
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};
