class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int j = 0, k = 0;
        int win_j = 0, win_k = 0;

        int ans = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            // NOTE: when goal == 0, j will not move, need to take care of it
            // Ex. [1, 0, 0], goal = 0
            if(j < i) j = i;
            if(k < i) k = i;

            while(j < n and win_j < goal){
                win_j += nums[j++];
            }

            while(k < n and (win_k < goal or (win_k == goal and nums[k] == 0))){
                win_k += nums[k++];
            }
            // no way to form one
            if(win_j < goal) break;
            // Ex. [0, 1, 0, 1, 0, 0] goal == 2
            //      i           j    k
            // [i, j) forms the shortest one, [i, k) forms the longest one

            ans += k-j+1;
            if(i == j) ans--;
            
            // leave nums[i]
            // NOTE: [1, 1, 1], goal == 0 will cause empty set
            if(i < j) win_j -= nums[i];
            if(i < k) win_k -= nums[i];
        }
        return ans;
    }
};
