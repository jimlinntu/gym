class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int max_length = 1;
        int length = 1;
        for(int i = 1; i < n; i++){
            if(nums[i-1] < nums[i]){
                length++;
                max_length = (max_length < length)?(length):(max_length);
            }else length = 1; // reset to 1 (itself)
        }
        return max_length;
    }
};
