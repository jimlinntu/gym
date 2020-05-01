class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int accumulated_sum = 0;
        int optimal_length = n+1;
        while(right < n){
            // Move the right pointer
            accumulated_sum += nums[right++];
            
            // Move the left pointer
            // (Note: "right" is actually right + 1)
            // (Note: accumulated_sum will always be the sum of [l, r))
            // (Note: accumluated_sum >= s will guard this for loop)
            for(; left < right && accumulated_sum >= s; left++){
                int length = right - left;
                // update the optimal length
                if(length < optimal_length){
                    optimal_length = length;
                }
                accumulated_sum -= nums[left];
            }
        }
        return optimal_length % (n+1);
    }
};
