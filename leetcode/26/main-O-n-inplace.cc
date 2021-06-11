class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int count = 1;
        for(int i = 1; i < n; i++){
            if(nums[count-1] != nums[i]){
                // Encounter a new number
                // Put them in front of the array
                // 1 1 1 2 2 2
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
