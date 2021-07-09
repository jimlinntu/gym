class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int max_len = 0;
        int r = 0;
        for(int i = 0; i < n; i++){
            // Expand r as right as possible
            while(r < n and freq[s[r]] == 0){
                freq[s[r++]]++;
            }
            // [i, r)
            max_len = max(max_len, r-i);
            // leaving i
            freq[s[i]]--;
        }
        return max_len;
    }
};
