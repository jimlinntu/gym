class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count_0 = 0;
        int l = 0;
        int ans = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] == 0) count_0++;
            // fix invalid (flip too much)
            while(l <= r and count_0 > k){
                if(nums[l] == 0) count_0--; // remove it
                l++;
            }
            // [l, r] is a longest substring ending at r
            // NOTE: l might > r
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
