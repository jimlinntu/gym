class Solution {
public:
    void merge_sort(int start, int end,
                    vector<int> &nums, vector<int> &indices,
                    vector<int> &counts){
        // indices[i] point to the original index
        // (i.e.) nums[indices[i]] == sorted_nums[i]
        // However, to avoid copy, here our nums will be sorted_nums after the recursive call
        if(end - start == 1){
            // do nothing, it has already been sorted!
            return;
        }
        // [start, end)
        int mid = (start + end)/2;
        vector<int> merged(end-start);
        vector<int> merged_indices(end-start);
        // nums: [start, mid) are sorted
        merge_sort(start, mid, nums, indices, counts);
        // nums: [mid, end) are sorted
        merge_sort(mid, end, nums, indices, counts);

        int l = start, r = mid;
        int length = 0;
        // use just for [start, mid)
        // For example: [2,5] [1,6] ==> [1, 2, 5, 6],
        //              even if 1 is put in the array first, 5 is greater than 1 too,
        //              so we should consider it too! 
        int accumulated_greater_than_right = 0;
        // merge algorithm: O(n)
        while(l < mid && r < end){
            if(nums[l] <= nums[r]){
                // put nums[l]
                counts[indices[l]] += accumulated_greater_than_right;
                merged[length] = nums[l];
                merged_indices[length] = indices[l];
                length++;
                l++;
            }else{
                // nums[l] > nums[r] occurs! Record there is a (left > right) case
                accumulated_greater_than_right++;
                // put nums[r]
                merged[length] = nums[r];
                merged_indices[length] = indices[r];
                length++;
                r++;
            }
        }
        // put the remaining into the merged
        // (Note: there is only one for loop will be executed of two for loops below)
        for(; l < mid; l++, length++){
            counts[indices[l]] += accumulated_greater_than_right;
            merged[length] = nums[l];
            merged_indices[length] = indices[l];
        }
        for(; r < end; r++, length++){
            merged[length] = nums[r];
            merged_indices[length] = indices[r];
        }
        // copy the merged to nums
        for(int i = 0; i < length; i++){
            nums[start+i] = merged[i];
            indices[start+i] = merged_indices[i];
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> indices(n);
        for(int i = 0; i < n; i++){
            indices[i] = i;
        }
        merge_sort(0, n, nums, indices, counts);
        return counts;
    }
};
