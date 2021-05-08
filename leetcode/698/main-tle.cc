class Solution {
public:
    int target_sum;
    int n;
    bool search(vector<int> &nums, int mask,
                int num_remain_subsets, int remain_sum){
        if(num_remain_subsets == 0 and remain_sum == 0) return true;
        if(remain_sum == 0){
            remain_sum = target_sum;
            num_remain_subsets--;
        }
        int cur = 1;
        for(int i = 0; i < n; i++, cur <<= 1){
            // if this number has not been used
            if((mask & cur) == 0 && remain_sum - nums[i] >= 0){
                int new_remain_sum = remain_sum - nums[i];
                if(search(nums, mask | cur, num_remain_subsets, new_remain_sum))
                    return true;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int allsum = 0;
        for(int num: nums) allsum += num;
        if(allsum % k) return false;
        n = nums.size();
        if(n < 1) return false;
        target_sum = allsum / k;
        // If there exists one element greater than target_sum, we cannot parition it
        for(int num: nums){
            if(num > target_sum) return false;
        }
        return search(nums, 0, k, 0);
    }
};
