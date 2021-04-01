class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int start = 0, end = n;
        int mid = (start + end) / 2;
        // find the maximum on the first half
        // Ex.
        //     [4, 5, 6, 7, 0, 1, 2]
        //      ^  ^  ^  ^*
        //     [0, 1, 2, 3, 4]
        //      ^  ^  ^  ^  ^*  just mod 5
        while(end - start != 1){
            if(nums[start] < nums[mid]){
                // [start, mid] are sorted
                // so the maximum is on the right of mid (or itself)
                start = mid;
            }else if(nums[start] > nums[mid]){
                // [mid, end) are sorted but is smaller than the first half!
                end = mid;
            }else assert(false);
            
            mid = (start + end) / 2;
        }
        // nums[mid] == max(nums)
        return nums[(mid+1) % n];
    }
};
