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
            int kk = k;
            int r = 0;
            for(int j = 0; j < n; j++){
                while(r < n){
                    if(s[r] == c) r++;
                    else if(kk > 0){
                        kk--;
                        r++;
                    }else break;
                }
                // [j, r) is the maximum range
                ans = max(ans, r-j);
                if(r - j == 0){
                    r = j+1; // next starting r
                }else{
                    if(s[j] != c) kk++; // restore kk
                }
            }
        }
        return ans;
    }
};
