class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 0) return 0;
        int prod = 1;
        int n = nums.size();
        int ans = 0;
        int l = 0;
        for(int r = 0; r < n; r++){
            prod *= nums[r];
            
            while(l <= r and prod >= k){
                prod /= nums[l];
                l++;
            }
            // [l, r] is the largest one ending at r
            ans += r-l+1;
        }
        return ans;
    }
};
