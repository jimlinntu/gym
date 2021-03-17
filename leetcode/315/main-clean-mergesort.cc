class Solution {
public:
    void merge_sort(int start, int end,
                    vector<vector<int>> &nums_and_indices,
                    vector<int> &counts){
        // [start, end)
        if(end - start == 1) return;
        int mid = (start + end) / 2;
        // [start, mid) are sorted
        merge_sort(start, mid, nums_and_indices, counts);
        // [mid, end) are sorted
        merge_sort(mid, end, nums_and_indices, counts);
        // Compute the number of reverse pairs
        // Perform **fake merge algorithm** (not actually put values)
        // (but just move two index pointers)
        // NOTE: when l == -1, even r >= 0, we do not care anymore!
        //       Because we only want to know the reverse pairs!
        for(int l = mid-1, r = end-1; l >= start; l--){
            // if the number at l is <= the number at r
            // it means the number at r should be put into the merged array first!
            while(r >= mid and nums_and_indices[l][0] <= nums_and_indices[r][0]){
                r--;
            }
            // the number at l is greater than (r+1) numbers in [mid, end)
            counts[nums_and_indices[l][1]] += r-mid+1;
        }
        // Real merge algorithm!
        // NOTE: nums_and_indices[i] == (num, i)
        //       we can easily observe that even if there is a tie,
        //       the right side's index will be always greater than the left side one!
        inplace_merge(nums_and_indices.begin()+start, nums_and_indices.begin()+mid,
                       nums_and_indices.begin()+end);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<vector<int>> nums_and_indices;
        for(int i = 0; i < n; i++) nums_and_indices.push_back(vector<int>{nums[i], i});
        merge_sort(0, n, nums_and_indices, counts);
        return counts;
    }
};
