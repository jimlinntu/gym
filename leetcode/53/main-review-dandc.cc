class Solution {
public:
    // T(n) = 2*T(n/2) + O(n)
    // => O(n log n)
    int solve(vector<int> &nums, int start, int end){
        // [start, end)
        if(start >= end) return INT_MIN;
        int mid = (start + end)/2;

        int l = solve(nums, start, mid); // [start, mid)
        int r = solve(nums, mid+1, end); // [mid+1, end)

        // Must use the middle one, expand left and right
        // Claim: in order to form a maximum subarray using the middle one,
        //        its left side and right side must both achieve their maximums
        // Proof: Assume left side doesn't achieve the maximum, we can use the maximum one
        //        to create a better subarray using the middle but with bigger sum
        // initially assume not taking any number from the left
        int left_sum = 0, cur_left_sum = 0;; 
        // not taking any number from the right
        int right_sum = 0, cur_right_sum = 0;
        for(int i = mid-1; i >= start; i--){
            cur_left_sum += nums[i];
            left_sum = max(left_sum, cur_left_sum);
        }
        for(int i = mid+1; i < end; i++){
            cur_right_sum += nums[i];
            right_sum = max(right_sum, cur_right_sum);
        }

        return max({l, r, left_sum + nums[mid] + right_sum});
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n);
    }
};
