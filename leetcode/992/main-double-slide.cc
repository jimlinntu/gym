struct Window{
    int c;
    int r;
    unordered_map<int, int> freq;
    Window(): c(0), r(0){
    }
};

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0) return 0;
        unordered_map<int, int> freq;
        int ans = 0;
        Window w_first, w;

        for(int i = 0; i < n; i++){
            // [i, w_first.r) will be the smallest r starting from i
            // that can form a good subarray
            while(w_first.r < n and w_first.c != k){
                if(w_first.freq[nums[w_first.r++]]++ == 0) w_first.c++;
            }

            if(w_first.c != k) break;
            // [i, w.r) will be the last r starting from i
            // that can form a good subarray

            while(w.r < n and (w.freq[nums[w.r]] > 0 or w.c < k)){
                if(w.freq[nums[w.r++]]++ == 0) w.c++;
            }

            ans += w.r - w_first.r + 1;
            // leaving nums[i]

            if(--w_first.freq[nums[i]] == 0){
                w_first.c--;
            }
            if(--w.freq[nums[i]] == 0){
                w.c--;
            }
        }
        return ans;
    }
};
