class WordDistance {
public:
    unordered_map<string, vector<int>> map;
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size(); i++){
            map[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto &l = map[word1];
        auto &r = map[word2];
        // See my pdf for more information
        int d = INT_MAX;
        int i = 0;
        // O(n)
        for(int j = 0; j < r.size(); j++){
            // go right until l[i] > r[j]
            while(i < l.size() and l[i] < r[j]){
                i++;
            }
            // l[i] > r[j]
            // check left
            if(i > 0) d = min(d, abs(l[i-1] - r[j]));
            // check right
            if(i < l.size()) d = min(d, abs(l[i] - r[j]));
        }
        return d;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
