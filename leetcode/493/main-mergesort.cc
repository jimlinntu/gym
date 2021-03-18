using LL = long long;
class Solution {
public:
    void merge_sort(int start, int end,
                    vector<int> &nums,
                    int &count){
        if(end - start == 1) return;
        int mid = (start + end) / 2;
        merge_sort(start, mid, nums, count);
        merge_sort(mid, end, nums, count);
        for(int l = mid-1, r = end-1; l >= start; l--){
            // You can imagine the numbers in [mid, end) are multiplied by 2!
            // if the number at l <= 2 * the number at r
            while(r >= mid and (LL)nums[l] <= 2LL * (LL)nums[r]){
                r--; // imagine you put r at the end of the merged array
            }
            // the number at l is greater than (r-mid+1) numbers to the right
            count += r-mid+1;
        }
        inplace_merge(nums.begin()+start, nums.begin()+mid, nums.begin()+end);
        return;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int count = 0;
        merge_sort(0, n, nums, count);
        return count;
    }
};
