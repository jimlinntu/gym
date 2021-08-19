class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Observe: Because this array only has n numbers
        // the largest smallest missing positive number is
        // [1, 2, 3, 4, 5, ... , n] -> n+1
        // We can ignore nonpositive numbers
        // Ex. [a0, a1, a2, a3, a4]

        for(int i = 0; i < n; i++){
            // Put nums[i] at nums[nums[i]-1] (imagine a hash table)
            // If it is not in [1, n], we ignore it because it is useless here
            // Otherwise, we will want to put nums[i] to nums[nums[i]-1]
            // If nums[nums[i]-1] is already put a nums[i], then we can stop
            while(0 < nums[i] and nums[i] <= n and nums[nums[i]-1] != nums[i]){
                // Put this number into its hash place
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
