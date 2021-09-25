class Solution {
public:
    int longestSubstring(string s, int k) {
        // Divide the search space by # of unique chars within the window
        int freq[256] = {0};
        int n = s.size();
        int len = 0;
        for(int i = 1; i <= 26; i++){
            fill(freq, freq+256, 0);
            int count = 0;
            int count_geq_k = 0;
            // Sliding window
            int l = 0;
            for(int r = 0; r < n; r++){
                freq[s[r]]++;
                if(freq[s[r]] == 1) count++;
                if(freq[s[r]] == k) count_geq_k++;

                // too many unique chars
                while(l <= r and count > i){
                    freq[s[l]]--;
                    if(freq[s[l]] == 0) count--;
                    if(freq[s[l]] == k-1) count_geq_k--;
                    // move l to the right
                    l++;
                }

                // [l, r] is the longest substring containing
                // at most i unique characters
                if(count == i and count == count_geq_k){
                    len = max(len, r-l+1);
                }
            }
        }
        return len;
    }
};
