class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int n = s.size();
        int l = 0;
        int ans = 0;
        for(int r = 0; r < n; r++){
            // add this character
            if(freq[s[r]]++ == 1){
                // shift our left boundary until it is valid again
                while(l < r and freq[s[r]] == 2){
                    freq[s[l++]]--;
                }
            }
            // [l, r]
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
