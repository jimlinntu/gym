class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Positve integers can not form a subarray whose product is less than k
        if(k <= 1) return 0;
        int start = 0, end = 0;
        int n = nums.size();
        int prod = 1;
        int ans = 0;
        while(end < n){
            prod *= nums[end++];
            // [start, end)
            // if the new number will cause >= k,
            // we can start to pop the number in front until it is less than k
            while(start < end and prod >= k){
                prod /= nums[start++];
            }
            // adding this number will introduce `end-start` new subarrays
            // Or `end-start` subarrays that ends at `end-1`
            ans += end - start;
        }
        return ans;
    }
};
