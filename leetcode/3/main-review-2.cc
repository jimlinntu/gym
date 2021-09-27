class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int freq[256] = {0};

        int l = 0;
        int longest = 0;
        for(int r = 0; r < n; r++){
            freq[s[r]]++;

            while(l <= r and freq[s[r]] > 1){
                freq[s[l++]]--;
            }
            // longest substring wo repeating ending at r
            longest = max(longest, r-l+1);
        }
        return longest;
    }
};
