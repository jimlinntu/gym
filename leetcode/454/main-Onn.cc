class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        // Observe: a + b + c + d == 0
        // (a from nums1, b from nums2 ...)
        // => a + b == -(c+d)
        // => We brute force all the possible sums of nums1 and nums2
        //    and then loop over nums3, nums4 again
        // => O(n^2)
        unordered_map<int, int> map;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                ++map[nums1[i]+nums2[j]]; // add one pair
            }
        }
        int ans = 0;
        auto e = map.end();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int s = nums3[i] + nums4[j];
                ans += map[-s];
            }
        }
        return ans;
    }
};
