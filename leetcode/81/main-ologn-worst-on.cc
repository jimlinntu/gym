class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        // Perform bsearch
        int start = 0, end = n;
        int mid = (start + end) / 2;
        auto is_in_range = [](int a, int b, int c){
            // if c is in [a, b]
            return a <= c and c <= b;
        };
        // if [start, end) forms the empty set, we stop
        while(start < end){
            int mid_val = nums[mid];

            if(mid_val == target) return true;

            if(nums[start] < mid_val){
                // [start, mid) are sorted
                assert(start < mid); // because nums[start] < nums[mid]
                if(is_in_range(nums[start], nums[mid-1], target)){
                    // target is in [start, mid)
                    end = mid;
                }else{
                    // target must not be in [start, mid) and [mid, mid]
                    start = mid+1;
                }
            }else if(nums[start] > mid_val){
                // [mid+1, end) are sorted
                // Edge case: [7, 2] -> if start == 0 and end == 2, mid == 1
                //            then mid + 1 == 2 >= n which cause nums[mid+1] invalid
                if(mid+1 < n and is_in_range(nums[mid+1], nums[end-1], target)){
                    start = mid+1;
                }else{
                    end = mid;
                }
            }else{
                // if nums[start] == nums[mid]
                if(nums[start] != nums[end-1]){
                    // same as nums[start] < mid_val case
                    // we can be sure [start, mid) are sorted
                    assert(start < mid); // because nums[start] != nums[end-1], start != end-1
                    if(is_in_range(nums[start], nums[mid-1], target)){
                        // target is in [start, mid)
                        end = mid;
                    }else{
                        // target must not be in [start, mid) and [mid, mid]
                        start = mid+1;
                    }
                }else{
                    // if nums[start] == nums[mid] == nums[end-1]
                    // We cannot be sure [start, mid) or [mid+1, end) are sorted
                    // we can only restrict [start, end) to [start+1, end)
                    start = start+1;
                    end = end-1;
                }
            }
            mid = (start + end) / 2;
        }
        return false;
    }
};
