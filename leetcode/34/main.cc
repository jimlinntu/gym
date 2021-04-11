class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        if(n == 0) return vector<int>{-1, -1};
        int start = 0, end = n;
        int mid = (start + end) / 2;
        // left bsearch
        // Edge cases:
        // [8, 8]
        //     ^ <----- mid
        while(end - start > 1){
            if(nums[mid] < target){
                // [mid, end)
                start = mid;
            }else if(nums[mid] > target){
                // [start, mid)
                end = mid;
            }else{
                // Ex. [8, 8]
                //         ^ <---- mid
                if(mid-1 >= start and nums[mid-1] == target) end = mid; // [start, mid)
                else{
                    // found: [mid, mid+1)
                    start = mid;
                    end = mid+1;
                }
            }
            mid = (start + end) / 2;
        }
        if(nums[mid] != target) return vector<int>{-1, -1};
        ans.push_back(mid);
        // right bsearch
        start = 0, end = n;
        mid = (start + end) / 2;
        while(end - start > 1){
            if(nums[mid] < target){
                // [mid, end)
                start = mid;
            }else if(nums[mid] > target){
                // [start, mid)
                end = mid;
            }else{
                // Ex. [8, 8]
                //         ^ <---- mid
                if(mid+1 < end and nums[mid+1] == target) start = mid+1; // [mid+1, end)
                else{
                    // found: [mid, mid+1)
                    start = mid;
                    end = mid+1;
                }
            }
            mid = (start + end) / 2;
        }
        ans.push_back(mid);
        return ans;
    }
};
