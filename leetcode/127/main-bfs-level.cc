class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0) return 0;
        int word_len = wordList[0].size();
        unordered_set<string> word_set(wordList.begin(), wordList.end());
        queue<string> q({beginWord});
        int level = 0;
        while(!q.empty()){
            // Traverse every node in this level
            for(int k = q.size(); k > 0; k--){
                string w = q.front();
                q.pop();
                // Expand this level's words
                for(int i = 0; i < word_len; i++){
                    char c = w[i];
                    for(int j = 0; j < 26; j++){
                        char new_c = 'a' + j;
                        if(c == new_c) continue;
                        // mutate this char
                        w[i] = new_c;
                        if(word_set.find(w) == word_set.end()) continue;
                        if(w == endWord) return level+2;
                        q.push(w);
                        word_set.erase(w); // remove it to indicate this node has been visited
                    }
                    w[i] = c; // restore this char
                }
            }
            level++; // go to the next level
        }
        return 0;
    }
};
