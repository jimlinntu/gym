class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // Check from the right to left
        int anchor = -1;
        for(int i = n-1; i >= 1; i--){
            if(nums[i-1] < nums[i]){
                anchor = i-1;
                break;
            }
        }
        // If this nums already reaches its largest permutation
        if(anchor == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        // nums[anchor] < nums[anchor+1] >= nums[anchor+2] ..... nums[n-1]
        // Observe that [anchor+1, n-1] has reached its largest permutation
        // Therefore, we cannot make it smaller.
        // And observe that nums[anchor] can become smaller
        // (at least swap it with nums[anchor+1])
        // But can we make it even smaller?
        // Yes! We just scan from anchor+1 -> n-1 until we find the smallest one
        // that is larger than nums[anchor]
        int target = anchor+1;
        for(int i = anchor+2; i < n; i++){
            // NOTE: must choose the rightmost one
            // Otherwise: [1, 3, 3] will WA because
            // -> [3, 1, 3] where [1, 3] is not decreasing
            if(nums[target] >= nums[i] and nums[i] > nums[anchor])
                target = i;
        }
        //     1 5 4 3 2 1
        // ->  2 5 4 3 1 1
        // After swapping, [anchor+1, n-1] is still sorted because
        // nums[target] > nums[anchor] and nums[anchor] >= nums[target+1]
        swap(nums[anchor], nums[target]);
        reverse(nums.begin()+anchor+1, nums.end());
    }
};
