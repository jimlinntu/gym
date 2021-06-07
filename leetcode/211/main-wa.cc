class WordDictionary {
public:
    /** Initialize your data structure here. */
    // Build a finitie state machine
    // isend[0]: starting state
    // isend[i]: whether state is an end state
    vector<bool> isend;
    // transition to the next state
    // trans[i]: the character that can transition from i to i+1
    vector<unordered_set<char>> trans;
    WordDictionary() {
        isend = vector<bool>(1, false);
    }
    
    void addWord(string word) {
        int n = word.size();
        // Extend the number of states
        if(n > trans.size()){
            isend.resize(n+1);
            trans.resize(n);
        }
        for(int i = 0; i < n; i++){
            // add this transition edge
            trans[i].insert(word[i]);
        }
        // Mark this state as an end state
        isend[n] = true;
    }
    
    bool search(string word) {
        int n = word.size();
        if(n == 0) return false;
        // Consider word as a stream of characters
        // check whether by using these characters, we can walk to an end state
        if(n > trans.size()) return false;
        for(int i = 0; i < n; i++){
            char c = word[i];
            if(c != '.' and trans[i].find(c) == trans[i].end()) return false;
            if(c == '.'){
                // Because # of states is trans.size()+1
                // this edge must contain at least one character
                assert(trans[i].size() > 0);
            }
        }
        // whether this state is an end state
        return isend[n];
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
