class Solution {
public:
    int minDistance(string word1, string word2) {
        // d(word1[0~i], word2[0~j]) = 
        // If word1[i] == word2[j]:
        //     d(word1[0~i-1], word2[0~j-1])
        // If word1[i] != word2[j]:
        //     Insert word2[j] on the back of word1[0~i]
        //     => d(word1[0~i], word[0~j-1]) + 1
        //     Insert word1[i] on the back of word2[0~j]
        //     => d(word1[0~i-1], word2[0~j]) + 1
        //     Replace word1[i] to word2[j] (or word2[j], it is the same)
        //     => d(word1[0~i-1], word2[0~j-1]) + 1
        //     Delete word1[i]
        //     => d(word1[0~i-1], word2[0~j]) + 1 (same as deletion)
        //     Delete word2[j]
        //     => d(word1[0~i], word2[0~j-1]) + 1 (same as deletion)
        // Define d(i, j) == d(word1[0~i-1], word2[0~j-1])
        // word1[0~-1] means the empty string
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> d(m+1, vector<int>(n+1, 0));
        for(int j = 0; j < n+1; ++j){
            // d("", word2[0~j-1]) needs j operations
            d[0][j] = j;
        }
        for(int i = 1; i < m+1; ++i){
            // d(word1[0~i-1], "") will need i operations apparently
            d[i][0] = i;
            for(int j = 1; j < n+1; ++j){
                if(word1[i-1] == word2[j-1]){
                    d[i][j] = d[i-1][j-1];
                }else{
                    d[i][j] = min({d[i][j-1]+1, d[i-1][j]+1, d[i-1][j-1]+1});
                }
            }
        }
        return d[m][n];
    }
};
