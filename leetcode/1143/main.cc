class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<int> lcs(n+1);
        // lcs(0, j) == text1: [0, 0) vs text2: [0, j)
        for(int j = 0; j <= n; j++){
            lcs[j] = 0;
        }
        // lcs(i, j)
        int prev;
        for(int i = 1; i <= m; i++){
            prev = lcs[0];
            lcs[0] = 0; // lcs(i, 0)
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    int tmp = prev;
                    prev = lcs[j];
                    lcs[j] = tmp + 1; // lcs(i, j) == lcs(i-1, j-1) + 1
                }else{
                    prev = lcs[j];
                    lcs[j] = max(lcs[j-1], lcs[j]);
                }
            }
        }
        return lcs[n];
    }
};
