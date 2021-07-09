class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int win_count = 0;
        unordered_map<char, int> freq;
        int max_len = 0;
        int r = 0;
        for(int i = 0; i < n; i++){
            // Expand as right as possible
            // freq[s[r]] > 0: this s[r] will not increase # of distinct chars
            // win_count < 2: after adding 1 s[r], our win_count should be <= 2
            while(r < n and (freq[s[r]] > 0 or win_count < 2)){
                if(freq[s[r++]]++ == 0) win_count++;
            }

            max_len = max(max_len, r-i);

            // remove s[i]
            if(--freq[s[i]] == 0) win_count--;
        }

        return max_len;
    }
};
