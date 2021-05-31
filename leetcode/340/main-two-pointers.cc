class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        if(k == 0) return 0;
        unordered_map<char, int> freq;
        int ans = 0;
        int count = 0; // count of distinct chars
        int r = 0;
        for(int i = 0; i < n; i++){
            // Go as right as possible
            while(r < n){
                // If there is a new distinct character, and our count is full
                // then we break the loop
                if(freq[s[r]] == 0 and count == k) break;
                // Add this character
                if(freq[s[r++]]++ == 0) count++;
            }
            // [i, r)
            ans = max(ans, r - i);
            // remove s[i]. Decrement count if we lose one distinct char
            if(--freq[s[i]] == 0) count--;
        }
        return ans;
    }
};
