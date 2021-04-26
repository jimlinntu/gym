class Solution {
public:
    int quickselect(vector<int> &nums, int start, int end){
        if(start >= end) return -1;
        int pivot = nums[start];
        int left = start;
        for(int i = start+1; i < end; i++){
            if(nums[i] >= pivot){
                left++;
                swap(nums[left], nums[i]);
            }
        }
        swap(nums[start], nums[left]);
        return left;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int start = 0, end = n;
        shuffle(nums.begin(), nums.end(), default_random_engine(0));
        while(start < end){
            int pidx = quickselect(nums, start, end);
            if(pidx == k-1) return nums[pidx];
            else if(pidx < k-1){
                start = pidx+1;
            }else{
                end = pidx;
            }
        }
        assert(false);
        return -1;
    }
};
