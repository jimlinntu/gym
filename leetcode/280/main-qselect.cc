class Solution {
public:
    int qselect(vector<int> &nums, int start, int end){
        // [start, end)
        if(start >= end) return -1;
        int num = nums[start];
        int idx = start;
        for(int i = start+1; i < end; i++){
            if(nums[i] <= num){
                swap(nums[++idx], nums[i]);
            }
        }
        // Put nums[start] to the middle as the splitting number
        // in [start, end) range
        swap(nums[start], nums[idx]);
        // and return its position
        return idx;
    }

    void k_smallest(vector<int> &nums, int k){
        shuffle(nums.begin(), nums.end(), default_random_engine(0));
        int l = 0, r = nums.size();
        while(l < r){
            int idx = qselect(nums, l, r);
            if(idx == k) return;
            if(idx < k){
                // kth smallest is in [idx+1, r)
                l = idx+1;
            }else{
                // kth smallest is in [l, idx)
                r = idx;
            }
        }
    }

    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        // Divide nums into 2 parts by quick selection algorithm
        // {a} and {b} where max{a} <= min{b}
        int num_a = (n+1) / 2;
        int num_b = n / 2;
        // Place {a} and {b} like
        // a b a b a or a b a b
        // We want [0, num_a) be the smallest among nums
        // NOTE: O(n) in average
        k_smallest(nums, num_a-1);
        // r is the index next position to put b
        int l = num_a, r = 1;
        if(l % 2 == 1) l = num_a + 1;
        while(l < n){
            // Put b to the r position
            swap(nums[l], nums[r]);
            // move forward by 2
            l += 2;
            r += 2;
        }
        return;
    }
};
