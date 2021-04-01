class Solution {
public:
    // find the maximum's index inside nums in O(log n) time
    // i.e. nums[find_max_idx(nums)] == max(nums)
    int find_max_idx(vector<int> &nums){
        int start = 0, end = nums.size();
        int front = nums[0];

        // Cases:
        // 1. [7, 0, 1]
        //     ^ <-------- in the "left" part
        // 2. [1, 2, 3]
        //     ^  ^  ^ <-- all in the "left" part
        // 3. [4, 5, 6, 1, 2, 3]
        //     ^  ^  ^ <---------- in the "left" part
        // if there is only one element inside [start, end), we should end
        int mid = (start+end)/2;
        while(start != end-1){
            int mid_val = nums[mid];
            if(mid_val > front){
                // this tells us we are in the "left" part
                // so things on the left of mid cannot be the max val's idx
                start = mid;
            }else if(mid_val <= front){
                // this tells us we are in the "right" part
                // so things on the right of mid cannot be the max val's idx
                end = mid; // NOTICE, [start, end)
            }else assert(false);
            mid = (start + end) / 2;
        }
        // nums[mid] == max(nums)
        return mid;
    }
    // perform binary searching within [start, end)
    // where nums within [start, end) are already sorted
    int bsearch(vector<int> &nums, int target, int start, int end){
        if(start >= end) return -1;
        // target should be inside [nums[start], nums[end-1]]
        if(target < nums[start] or nums[end-1] < target) return -1;

        int mid = (start + end) / 2;
        while(start < end){
            int mid_val = nums[mid];
            if(mid_val < target){
                start = mid+1; // not including mid
            }else if(mid_val > target){
                end = mid; // not including mid
            }else{
                return mid; // hit
            }
            mid = (start + end)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        int max_idx = find_max_idx(nums);
        return max(bsearch(nums, target, 0, max_idx+1),
                   bsearch(nums, target, max_idx+1, nums.size()));
    }
};
