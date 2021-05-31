class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        // O(26 * n) = O(n)
        for(int i = 0; i < 26; i++){
            // Search for 'A'+i
            char c = 'A' + i;
            // Two pointers algorithm
            // with k tolerence characters
            int start = 0, end = 0;
            int kk = k;
            while(start < n){
                // Go as right as possible (with kk tolerence)
                while(end < n){
                    if(s[end] == c) end++;
                    else if(kk > 0){
                        kk--;
                        end++;
                    }else break;
                }
                // [start, end) is the maximum string starting from s[start]
                ans = max(ans, end-start);
                // Move start one step
                if(end-start > 0){
                    // recover one tolerence point
                    if(s[start++] != c) kk++;
                }else{
                    start++;
                    end = start;
                }
            }
        }
        return ans;
    }
};
