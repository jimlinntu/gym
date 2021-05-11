class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    void solve(vector<int> &nums, int startidx){
        if(startidx >= n){
            ans.push_back(path);
            return;
        }
        // Every element can be place at startidx
        for(int i = startidx; i < n; i++){
            // Same numbers will ALWAYS be concecutive
            // because we have sorted
            // See the proof I have provided in the same folder
            if(i >= startidx+1 and nums[i-1] == nums[i]) continue;
            swap(nums[startidx], nums[i]);
            path.push_back(nums[startidx]);

            solve(nums, startidx+1);

            swap(nums[startidx], nums[i]);
            path.pop_back();
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

        // Proof: detailed proof is in this folder
        // Short Proof:
        // Consider without * marks.
        // If there are duplicate numbers after *, they must be consecutive!
        // It is because every time we will swap the FIRST number of a consecutive section
        // Ex.
        //  v (startidx)
        // [1, 2, 2, 3, 3, 3, 4, 4]
        //  ^  ^     ^        ^
        // ^ denotes the place we will swap it with startidx
        // It will be easy that swapping will not cut a consecutive section!
        
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};
