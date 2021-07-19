class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        int d = INT_MAX;
        if(word1 == word2){
            int j = 0;
            for(int i = 0; i < n; i++){
                if(wordsDict[i] != word1) continue;

                // Find the next one
                while(j < n and (j <= i or wordsDict[j] != word2)){
                    j++;
                }
                if(j == n) break;
                d = min(d, j-i);
            }
        }else{
            int j = 0;
            for(int i = 0; i < n; i++){
                if(wordsDict[i] != word1) continue;

                // Find the smallest j s.t.
                // 1) wordsDict[j] == word2
                // 2) j > i
                int prev_j = -1;
                while(j < n and (j <= i or wordsDict[j] != word2)){
                    if(j < i and wordsDict[j] == word2) prev_j = j;
                    j++;
                }
                // prev_j must be the largest k s.t. k < i and wordsDict[k] == word2
                // j must be the largest k s.t. k > i and wordsDict[k] == word2
                
                if(prev_j != -1) d = min(d, i-prev_j);
                if(j < n) d = min(d, j-i);
            }
        }
        return d;
    }
};
