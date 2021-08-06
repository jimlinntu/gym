class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int n = s.size();
        int ans = 0;
        int r = 0;
        for(int l = 0; l < n; l++){
            while(r < n and freq[s[r]] == 0){
                freq[s[r++]]++;
            }
            // [l, r)
            ans = max(ans, r-l);

            freq[s[l]]--;
        }
        return ans;
    }
};
