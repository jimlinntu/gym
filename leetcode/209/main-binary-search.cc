int search_smallest_index(int i, int n, int lower_bound, vector<int> &prefix_sums){
    // 0-index
    int start = i;
    int end = n-1;
    // Even the largest one lower than the current lower_bound, return -1
    if(prefix_sums[end+1] < lower_bound) return -1;
    while(start != end){
        int middle = (start + end) / 2;
        if(prefix_sums[middle+1] >= lower_bound){
            // throw away the right part, because we have at least
            // one nums[middle] >= lower_bound
            end = middle;
        }else{
            // throw away the left part, because until nums[middle]
            // there is no element >= lower_bound
            start = middle+1;
        }
    }
    return start;
}

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        // Note: prefix_sum is sorted automatically (cause nums[i] > 0)
        vector<int> prefix_sums(n+1); // 1-index
        for(int i = 0; i < n; i++){
            prefix_sums[i+1] = prefix_sums[i] + nums[i];
        }
        // O(n log n) algorithm
        int optimal_length = n+1;
        for(int i = 0, j; i < n; i++){
            // Binary search for the least j s.t. p_j >= s + p_{i-1}
            j = search_smallest_index(i, n, s+prefix_sums[i], prefix_sums);
            if(j != -1 && (j-i+1) < optimal_length){
                optimal_length = j - i + 1;
            }
        }
        return optimal_length % (n+1); // n+1 because zero
    }
};
