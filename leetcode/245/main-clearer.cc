class Solution {
public:
    int shortestWordDistance(vector<string>& w, string word1, string word2) {
        int n = w.size();
        int d = INT_MAX;
        bool is_same = (word1 == word2);
        
        int idx1 = -1, idx2 = -1;
        for(int i = 0; i < n; i++){
            if(w[i] == word1){
                // idx1 must be the closest index on the left of i
                if(is_same and idx1 != -1) d = min(d, i - idx1);
                // idx2 must be the closest index on the left of i
                if(!is_same and idx2 != -1) d = min(d, i - idx2);
                idx1 = i;
            }else if(w[i] == word2){
                idx2 = i;
                // idx1 must be the closest index on the left of i
                if(idx1 != -1) d = min(d, i - idx1);
            }
        }
        return d;
    }
};
