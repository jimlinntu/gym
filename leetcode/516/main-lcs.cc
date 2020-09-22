class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> lcs(n+1);
        // s: [0, 0); reverse(s): [0, j)
        for(int j = 0; j <= n; j++){
            lcs[j] = 0;
        }
        // s: [0, i); reverse(s): [0, j)
        int prev;
        for(int i = 1; i <= n; i++){
            prev = lcs[0];
            // s: [0, i); reverse(s): [0, 0)
            lcs[0] = 0;
            for(int j = 1; j <= n; j++){
                if(s[i-1] == s[n-j]){
                    int tmp = prev;
                    prev = lcs[j];
                    lcs[j] = tmp + 1;
                }else{
                    prev = lcs[j];
                    int delete_s = lcs[j];
                    int delete_rev_s = lcs[j-1];
                    lcs[j] = max(delete_s, delete_rev_s);
                }
            }
        }
        return lcs[n];
    }
};
