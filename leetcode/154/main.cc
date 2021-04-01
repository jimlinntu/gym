class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        assert(n >= 1);
        int start = 0, end = n;
        int mid = (start + end - 1)/2;
        // NOTE:
        // Cases:
        // 1. [1, 0]: start == 0, end == 1, mid == 0
        // 2. [0, 1]
        // 3. [0, 0]
        while(end - start != 1){
            if(nums[mid] < nums[end-1]){
                end = mid+1;
            }else if(nums[mid] > nums[end-1]){
                start = mid+1;
            }else{
                if(nums[start] == nums[end-1]){
                    // Cases:
                    // 1. [7, 7, 7, 4, 7]
                    // 2. [7, 4, 7, 7, 7]
                    end = end-1;
                }else{
                    // [mid, end) are sorted
                    end = mid+1;
                }
            }
            mid = (start + end - 1)/2;
        }
        return nums[mid];
    }
};
