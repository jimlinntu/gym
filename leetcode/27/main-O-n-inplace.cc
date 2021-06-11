class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            // Throw this number to the end of this array
            while(n >= 1 and i < n and nums[i] == val){
                swap(nums[i], nums[n-1]);
                n--;
            }
        }
        return n;
    }
};
