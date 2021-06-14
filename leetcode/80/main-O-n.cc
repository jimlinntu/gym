class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int k = 2;
        for(int i = 2; i < n; i++){
            // Ex. 2 3 3 3 3 3 3 3 3
            //       ^ ^           i
            // check two numbers at the end of the result array
            if(nums[k-1] != nums[i] or nums[k-2] != nums[i]){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
