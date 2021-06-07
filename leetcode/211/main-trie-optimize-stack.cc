struct Node {
    bool is_word;
    Node *child[26];
    Node(){
        is_word = false;
        fill(child, child+26, nullptr);
    }
    ~Node(){
        for(int i = 0; i < 26; i++){
            if(child[i] != nullptr) delete child[i];
        }
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Node *root;
    WordDictionary() {
        root = new Node();
    }
    ~WordDictionary(){
        delete root;
    }
    
    void addWord(string word) {
        Node *cur = root;
        for(char c: word){
            int i = c-'a';
            if(cur->child[i] == nullptr) cur->child[i] = new Node();
            cur = cur->child[i];
        }
        cur->is_word = true;
    }

    bool _search(Node *cur, string &word, int idx){
        // no way to walk further
        if(cur == nullptr) return false;
        if(idx == word.size()){
            return cur->is_word;
        }
        if(word[idx] == '.'){
            // search every branch
            for(int i = 0; i < 26; i++){
                // if one branch is valid, we can report true
                if(_search(cur->child[i], word, idx+1))
                    return true;
            }
            return false;
        }
        // Walk until we encounter a '.'
        for(; idx < word.size() && word[idx] != '.' && cur != nullptr; idx++){
            cur = cur->child[word[idx]-'a'];
        }
        return _search(cur, word, idx);
    }
    
    bool search(string word) {
        return _search(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
