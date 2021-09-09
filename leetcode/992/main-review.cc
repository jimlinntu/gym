class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        // at most k, at most k-1
        unordered_map<int, int> freq1, freq2;
        int ans = 0;
        int l1 = 0, l2 = 0;
        for(int r = 0; r < n; r++){
            int num = nums[r];
            if(freq1[num]++ == 0) count1++;
            if(freq2[num]++ == 0) count2++;

            while(l1 <= r and count1 > k){
                // remove nums[l1] from the window
                if(--freq1[nums[l1]] == 0) count1--;
                l1++;
            }
            // [l1, r] contains at most k distinct numbers

            while(l2 <= r and count2 > k-1){
                if(--freq2[nums[l2]] == 0) count2--;
                l2++;
            }
            // [l2, r] contains at most k-1 distinct numbers
            
            if(count1 != k) continue;

            // [l1, r] contains at most k distinct numbers (longest)
            // [l2, r] contains at most k-1 distinct numbers (longest)
            // Therefore, [i, r] can form exactly k distinct numbers and ends at r
            // where l1 <= i < l2
            ans += l2-l1;
        }
        return ans;
    }
};
