class Solution {
public:
    // check whether we can segment this array by <= m groups and the largest group <= value
    // NOTE: If we can segment it into say m-1 groups, we can trivially make to into m groups
    bool greedy(vector<int> &nums, int value, int m){
        int cur_seg = 0;
        for(int num: nums){
            if(num > value) return false;
            if(cur_seg + num <= value) cur_seg += num;
            else{
                cur_seg = num; // the new segment
                m--;
            }
            // We cannot segment this array by m groups and the largest group <= value
            // Because we still have remaining numbers
            if(m == 0) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        assert(m <= n);
        // Binary Search over [max(nums), sum(nums)]
        // NOTE: sum(nums) <= 10^6 * 1000 == 10^9 <= 2147483647
        int left_bound = 0, right_bound = 0;
        for(int num: nums){
            left_bound = max(left_bound, num);
            right_bound += num;
        }
        // We want to find the smallest value k
        // s.t. this array can be segmented into m groups while the largest group == k
        int middle = (left_bound + right_bound) / 2;
        while(left_bound < right_bound){
            if(!greedy(nums, middle, m)){
                // k is in [middle+1, right_bound]
                left_bound = middle+1;
            }else{
                // k is in [left_bound, middle]
                right_bound = middle;
            }
            middle = (left_bound + right_bound) / 2;
        }
        assert(left_bound == right_bound);
        return left_bound;
    }
};
