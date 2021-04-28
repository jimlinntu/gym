struct Node {
    bool is_word;
    Node *children[26];
    Node(){
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        is_word = false;
    }
    ~Node(){
        for(int i = 0; i< 26; i++){
            if(children[i] != nullptr) delete children[i];
        }
    }
};
constexpr int char2idx(char c){
    return c-'a';
}

class Trie {
public:
    Node *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    ~Trie(){
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        for(char c: word){
            if(cur->children[char2idx(c)] == nullptr)
                cur->children[char2idx(c)] = new Node();
            cur = cur->children[char2idx(c)];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = find(word);
        if(cur != nullptr and cur->is_word) return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = find(prefix);
        return cur != nullptr;
    }
private:
    Node *find(string &w){
        Node *cur = root;
        for(int i = 0; i < w.size() && cur != nullptr; i++){
            cur = cur->children[char2idx(w[i])];
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
