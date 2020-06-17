
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // itself as exist, -1 as no exist
        // nums[i-1] == whether the number i exists
        // O(n)
        for(int i = 0; i < n; i++){
            int val = nums[i];
            nums[i] = -1; // set it as no exist
            // Keep labeling them for their existence
            while(1 <= val and val <= n){
                // Save the target value as the next one
                int next_val = nums[val-1];
                // Tag this val as existing
                nums[val-1] = val;
                // Ex. [1, 1] will cause an infinite loop
                if(val == next_val) break;
                val = next_val;
            }
        }
        // Return the first index that corresponds to a False
        for(int i = 0; i < n; i++){
            if(nums[i] == -1) return i+1;
        }
        return n+1;
    }
};
