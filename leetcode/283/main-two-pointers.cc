class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        // O(n)
        while(i < n and j < n){
            for(; i < n; i++){
                if(nums[i] == 0) break;
            }
            for(j = max(i, j); j < n; j++){
                if(nums[j] != 0) break;
            }
            if(i < n and j < n) swap(nums[i], nums[j]);
        }
    }
};
