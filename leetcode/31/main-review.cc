class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // [8, 2, 3, 9, 1, 2, 3]
        //              *  *  *
        //              1  3  2
        // [1 2 3 2 5 4 3 2 1]
        //
        // [1 2 3 3 1 2 2 4 5]
        //
        // [3 1 3 4 5]
        //    + + + +
        //  3 1 3 5 4
        // 1. Find the rightmost increasing subarray
        // 2. Swap the second from the right with the next greater number
        // 3. reverse the rightmost part
        int n = nums.size();
        if(n == 1) return;
        // Edge case: [3, 2, 1]
        bool decreasing = true;
        for(int i = 1; i < n; i++){
            if(nums[i-1] < nums[i]){
                decreasing = false;
                break;
            }
        }
        if(decreasing){
            reverse(nums.begin(), nums.end());
            return;
        }
        // 1. Find the rightmost increasing subarray
        int anchor_idx = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                anchor_idx = i;
                break;
            }
        }
        // 2. Swap the second from the right with the next greater number

        int to_swap = -1;
        for(int i = anchor_idx+1; i < n; i++){
            if(nums[anchor_idx] < nums[i]){
                // empty
                if(to_swap == -1) to_swap = i;
                else if(nums[anchor_idx] < nums[to_swap]){
                    to_swap = i;
                }
            }
        }
        // 3. reverse the rightmost part
        swap(nums[anchor_idx], nums[to_swap]);
        //
        reverse(nums.begin()+anchor_idx+1, nums.end());
        return;
    }
};
