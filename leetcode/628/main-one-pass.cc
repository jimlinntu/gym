class Solution {
public:
    int maximumProduct(vector<int>& nums) {
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
        
        // If we does not want a sorting, we can use 5 variables to store
        // nums[0], nums[1], nums[n-1], nums[n-2], nums[n-3]
        
        int nums_0 = INT_MAX, nums_1 = INT_MAX; // minimum
        int nums_n_1 = INT_MIN, nums_n_2 = INT_MIN, nums_n_3 = INT_MIN; // maximum

        for(int x: nums){
            // minimum
            if(x < nums_0){
                nums_1 = nums_0;
                nums_0 = x;
            }else if(x < nums_1){
                nums_1 = x;
            }
            // maximum
            if(x > nums_n_1){
                nums_n_3 = nums_n_2;
                nums_n_2 = nums_n_1;
                nums_n_1 = x;
            }else if(x > nums_n_2){
                nums_n_3 = nums_n_2;
                nums_n_2 = x;
            }else if(x > nums_n_3){
                nums_n_3 = x;
            }
        }
        return max(nums_0*nums_1*nums_n_1, nums_n_1*nums_n_2*nums_n_3);
    }
};
