class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int allsum = 0;
        int maxnum = 0;
        int n = nums.size();
        for(int num: nums){
            allsum += num;
            maxnum = max(maxnum, num);
        }
        int target_sum = allsum / k;
        // Impossible to parition them into k subsets
        if(allsum % k) return false;
        if(n < 1) return false;
        // If there exists one element greater than target_sum, we cannot parition it
        if(maxnum > target_sum) return false;
        assert(k <= n);
        // Because we are already sure (maxnum <= target_sum)
        // Then if target_sum == 0, it can only be: {0, 0, 0, ... 0}
        if(target_sum == 0) return true;
        // Define:
        // select(nums, mask) == the numbers selected by mask
        // dp[mask] ==
        //          whether we can partition select(nums, mask) into
        //          cell(sum(select(nums, mask)) / target) groups and
        //          at most one group is non-full (the sum of that group < target)
        //          if yes, assign: sum(select(nums, mask)) % target
        //          otherwise, assign: -1
        //          (i.e. Or you can think it at most one group will have a sum < target)

        // Recursion:
        // dp[mask] == for every i satisfying (mask & (1 << i)) > 0 and
        //             dp[mask ^ (1 << i)] != -1 and
        //             dp[mask ^ (1<< i)] + nums[i] <= target
        //             (i.e. nums[i] is in the nonfull group)
        //             assign: sum(select(nums, mask)) % target
        //             If there is not such case, assign: -1
        // NOTE: the reason why we need to iterate over every i is because
        //       every nums[i] can possibly be in the nonfull group!
        //       And because we do not know which nums[i] is in the nonfull group,
        //       we must enumerate all possible i!

        // Ex. dp[{4, 4, 1}] and target == 5
        // Apparently, dp[{4, 4}] == -1 because we cannot put {4, 4}
        // into cell(8/5) (== 2) while there are TWO groups non-full!!!
        // if we only consider dp[{4, 4}] and {1}, we will accidentally conclude that
        // dp[{4, 4, 1}] == false, which is WRONG!!!
        // because we can group them like: {{4, 1}, {1}} which only one non-full group!
        int n_subsets = 1 << n;
        int dp[(1 << 16)];
        fill(dp, dp + (1 << 16), -1);
        dp[0] = 0;
        for(int mask = 0; mask < n_subsets; mask++){
            if(dp[mask] == -1) continue;
            for(int i = 0, select_bit = 1; i < n; i++, select_bit <<= 1){
                // if that number has already been selected
                if((mask | select_bit) == mask) continue;
                // nums[i] is in the non-full group
                if(dp[mask] + nums[i] <= target_sum){
                    dp[mask | select_bit] = (dp[mask] + nums[i]) % target_sum;
                }
            }
        }
        // when selecting all numbers, whether it can form at most one non-full group?
        return dp[(1 << n) -1] != -1;
    }
};
