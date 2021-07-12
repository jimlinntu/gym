class Solution {
public:
    int num_of_pairs_dist_leq(vector<int> &nums, int dist){
        // sliding window
        int n = nums.size();
        int r = 0;
        int s = 0;
        for(int i = 0; i < n; i++){
            while(r < n and nums[r]-nums[i] <= dist){
                r++;
            }
            // [i, r) contains: (i, i+1), (i, i+2) ... (i, r-1)
            s += r-(i+1);
        }
        return s;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        // Naive: O(n^2): list all numbers and then perform a quick select
        // Binary search over the value space:
        // O(nlogn + n log (max(nums)-min(nums)))
        int n = nums.size();
        sort(nums.begin(), nums.end());
        assert(1 <= k and k <= n * (n-1) / 2);
        int l = 0, r = nums.back()-nums[0];
        while(l <= r){
            int mid = (l + r) / 2;
            int s = num_of_pairs_dist_leq(nums, mid);
            // find the leftmost one
            if(s >= k){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};
