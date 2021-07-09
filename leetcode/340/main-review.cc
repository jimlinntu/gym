class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(k == 0) return 0;
        int n = s.size();
        int max_len = 0;
        int win_count = 0;
        unordered_map<char, int> freq;
        int r = 0;
        for(int i = 0; i < n; i++){
            // Expand as right as possible
            while(r < n and (freq[s[r]] > 0 or win_count < k)){
                if(freq[s[r++]]++ == 0) win_count++;
            }
            max_len = max(max_len, r-i);
            if(--freq[s[i]] == 0) win_count--;
        }
        return max_len;
    }
};
