class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[26] = {0};
        int max_len = 0;
        int max_count = 0;
        int r = 0;
        // Sliding window
        for(int i = 0; i < n; i++){
            // expanding right until invalid
            // NOTE: max_count is fake sometimes
            //       but it will not affect our answer because
            // Case 1: r-l == true_max_count + k
            //         In this case, the first time we find max_count == true_max_count
            //         it will be expanded as r-l length
            //         Even if sometimes max(freq) < max_count,
            //         but we use max_count to expand, it will at most be max_count + k
            //         which will not affect our answer
            // Case 2: r-l < true_max_count + k
            //         This indicates s.size() == r-l
            //         because if s.size() > r-l, this window can be expanded more!
            //         In this case, the first loop will find the answer

            // if after adding this character, this can be expanded further
            // we add this character at s[r]
            while(r < n and max(max_count, freq[s[r]-'A']+1) + k > r-i){
                max_count = max(max_count, ++freq[s[r++]-'A']);
            }
            // [i, r)
            max_len = max(max_len, r - i);
            // leaving i
            freq[s[i]-'A']--;
        }

        return max_len;
    }
};
