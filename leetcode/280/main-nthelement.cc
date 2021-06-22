class Solution {
public:
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
        nth_element(nums.begin(), nums.begin()+num_a-1, nums.end());
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
