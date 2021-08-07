class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // Case 1: all positive => nums[n-1] * nums[n-2] * nums[n-3]
        // Case 2: all negative => nums[n-1] * nums[n-2] * nums[n-3]
        // Case 3: # of positive >= 3 and # of negative >= 2
        // max(nums[n-1] * nums[n-2] * nums[n-3], nums[0]*nums[1]*nums[n-1])
        // Case 4: # of positive >= 3 and # of negative < 2
        // nums[n-1] * nums[n-2] * nums[n-3]
        // Case 5: # of positive < 3 and # of negative >= 2
        // nums[0] * nums[1] * nums[n-1]
        // Case 6: # of positive < 3 and # of negative < 2 and contain a zero
        // nums[n-1] * nums[n-2] * nums[n-3] == 0
        // Case 6: # of positive < 3 and # of negative < 2 and does not contain zeros
        // Because (# of positive) + (# of negative) <= 3
        // we just directly compute nums[0]*nums[1]*nums[2]!
        
        // In summary, max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3])
        // gives the answer!
        return max(nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]);
    }
};
