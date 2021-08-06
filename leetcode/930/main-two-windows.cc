class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Brute force: O(n^2) to check each subarray
        // Sliding window
        // [1, 0, 1, 0, 1]
        //  l        r
        // for each i, go right until we find the first j
        // s.t. sum(nums[i~j]) == goal
        // and then we find the first k s.t.
        // s.t. sum(nums[i~k]) == goal+1
        // After knowing this, [i, j], [i, j+1], ... [i, k-1]
        // are all the subarrays [i, ?] can form
        
        int j = 0, k = 0;
        int win_j = 0, win_k = 0; // two windows
        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // Deal with edge cases like:
            // [0, 0, 0], goal = 0
            j = max(j, i);
            while(j < n and win_j < goal){
                win_j += nums[j++];
            }
            // k will at least move 1, so we don't need to take k = max(k, i)
            while(k < n and win_k < goal+1){
                win_k += nums[k++];
            }
            
            if(win_j < goal) break; // no way to find a subarray anymore
            // j, k are the first one making it goal/goal+1
            // sum([i, j)) == goal
            // sum([i, k)) == goal+1

            // [i, j), [i, j+1) ... [i, k-1) are all the subarrays whose sum == goal
            // NOTE: Remember to exclude the empty array
            if(win_k == goal+1){
                ans += (k-1)-j+1;
            }else{
                ans += k-j+1;
            }
            
            if(j == i) ans--; // exclude the empty array
            // leave this position
            if(j != i) win_j -= nums[i];
            win_k -= nums[i];
        }
        return ans;
    }
};
