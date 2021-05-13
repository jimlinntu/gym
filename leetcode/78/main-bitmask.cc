class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // ans[mask] == the nums chosen by the mask
        int power_set_n = 1 << n;
        vector<vector<int>> ans(power_set_n);
        // Complexity: O(n * 2^n)
        for(int mask = 1; mask < power_set_n; mask++){
            for(int i = 0, bit = 1; i < n; i++, bit <<= 1){
                if(mask & bit) ans[mask].push_back(nums[i]);
            }
        }
        return ans;
    }
};
