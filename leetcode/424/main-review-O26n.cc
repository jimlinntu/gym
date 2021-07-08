class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_len = 0;
        // Separate the search space by A-Z
        for(int i = 0; i < 26; i++){
            char c = 'A' + i;
            int kk = k;
            int r = 0;
            for(int j = 0; j < n; j++){
                // go as right as possible until kk is used up
                while(r < n and (s[r] == c or kk > 0)){
                    // perform an operation
                    if(s[r] != c) kk--;
                    r++;
                }
                // [j, r)
                max_len = max(max_len, r - j);
                
                // move j to the right
                // restore our kk by 1 if s[j] != c
                if(s[j] != c) kk++;
            }
        }
        return max_len;
    }
};
