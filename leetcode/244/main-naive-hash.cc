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
        int d = INT_MAX;
        for(int i: l){
            for(int j: r){
                d = min(d, abs(i-j));
            }
        }
        return d;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
