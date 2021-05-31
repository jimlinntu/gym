class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        // Max frequency we have seen **so far**
        // **NOT** the max frequency within [i, r) window
        // Ex. ABACD
        int max_freq = 0;
        int freq[26] = {0};
        int r = 0;
        for(int i = 0; i < n; i++){
            // Extend r as right as possible
            while(r < n){
                int f = freq[s[r]-'A']+1;
                // Adding this character will break validity
                // NOTE: we are testing if [i, r] is valid
                // that is why we use r + 1 - i
                if(r + 1 - i > max(max_freq, f) + k) break;
                max_freq = max(max_freq, f);
                freq[s[r]-'A'] = f;
                r++; // move right
            }
            // [i, r)
            ans = max(ans, r-i);
            // Move i to the right (throw away s[i])
            freq[s[i]-'A']--;
        }
        return ans;
    }
};
