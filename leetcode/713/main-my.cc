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
                // Throw away the front number if the prod is stil >= k
                // We should consider all subarray starting from `start` when we throw it away
                // NOTE: should not consider numbers[end-1], because it is cause that prod >= k
                ans += end - start - 1;
                prod /= nums[start++];
            }
        }
        // [start, end)'s product < k
        // which means all subarray of [start, end) < k
        while(start < end and prod < k){
            ans += end - start;
            start++;
        }
        return ans;
    }
};
