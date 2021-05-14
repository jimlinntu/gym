class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // O(n): using the technique like 3-color sorting
        // [0, j) are the region we already complete
        for(int i = 0, j = 0; i < n; i++){
            if(nums[i] != 0) swap(nums[j++], nums[i]);
        }
    }
};
