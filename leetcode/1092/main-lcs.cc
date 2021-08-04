class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        // Observe:
        // In order to minimize the length of the superseq
        // we must "reuse" a character as much as possible
        // if a character is reused by 2 seqs, that will be great
        // This problem can be transformed into
        // Find the LCS and then add characters that is not inside the LCS

        // Compute LCS table
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = (s1[0] == s2[0]);
        for(int i = 1; i < m; i++){
            if(s1[i] == s2[0]) dp[i][0] = 1;
            else dp[i][0] = dp[i-1][0];
        }
        for(int j = 1; j < n; j++){
            if(s1[0] == s2[j]) dp[0][j] = 1;
            else dp[0][j] = dp[0][j-1];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // delete s1[i] or s2[j]
            }
        }
        // Backtrack to get the LCS string
        vector<bool> use1(m, false), use2(n, false);
        int p1 = m-1, p2 = n-1;
        while(p1 >= 0 and p2 >= 0){
            if(p1 == 0 or p2 == 0){
                if(s1[p1] == s2[p2]){
                    use1[p1] = use2[p2] = true;
                    p1--, p2--;
                }else if(p1 > 0){
                    p1--; // delete p1
                }else if(p2 > 0){
                    p2--;
                }else break;
                continue;
            }
            // this char is in the LCS
            if(s1[p1] == s2[p2]){
                use1[p1] = use2[p2] = true;
                p1--, p2--;
            }else if(dp[p1-1][p2] >= dp[p1][p2-1]){
                // delete p1 is better
                p1--;
            }else{
                // delete p2 is better
                p2--;
            }
        }
        // the LCS = dp[m-1][n-1] = x
        // Then the superseq == x + (m-x) + (n-x) = m+n-x
        string ans(m+n-dp[m-1][n-1], 0);
        int idx = 0;
        for(p1 = 0, p2 = 0; p1 < m or p2 < n;){
            if(p1 >= m){
                ans[idx++] = s2[p2++];
            }else if(p2 >= n){
                ans[idx++] = s1[p1++];
            }else if(use1[p1] == false){
                ans[idx++] = s1[p1++]; // put s1[p1]
            }else if(use2[p2] == false){
                ans[idx++] = s2[p2++]; // put s2[p2]
            }else{
                assert(use1[p1] and use2[p2]);
                ans[idx++] = s1[p1]; // put s1[p1] (== s2[p2])
                p1++, p2++; // a common character
            }
        }
        return ans;
    }
};
