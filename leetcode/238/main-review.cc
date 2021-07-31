class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n, 1);
        // define prefix[i] = nums[0] * nums[1] ... * nums[i-1]
        // and    suffix[i] = nums[i+1] * nums[i+2] ... nums[n-1]
        // out[i] = prefix[i] * suffix[i]
        // 1. Compute prefix[i] but place it on out[i]
        for(int i = 1; i < n; i++){
            out[i] = out[i-1] * nums[i-1];
        }
        // 2. Compute prefix[i] * suffix[i]
        int suffix = 1;
        for(int i = n-2; i >= 0; i--){
            suffix *= nums[i+1];
            out[i] = out[i] * suffix;
        }
        return out;
    }
};
