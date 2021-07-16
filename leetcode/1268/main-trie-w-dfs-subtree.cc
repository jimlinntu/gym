const int MAX_PROD = 3;

struct TrieNode {
    TrieNode *children[256];
    int word_idx; // because products are gauranteed unique, otherwise this should be a vector

    TrieNode(): word_idx(-1){
        for(int i = 0; i < 26; i++)
            children[i+'a'] = nullptr;
    }
    ~TrieNode(){
        for(int i = 0; i < 26; i++){
            if(children[i+'a']) delete children[i+'a'];
        }
    }
};

void add_word(string &word, int word_idx, TrieNode *root){
    TrieNode *cur = root;
    for(char c: word){
        if(cur->children[c] == nullptr) cur->children[c] = new TrieNode();
        cur = cur->children[c];
    }
    cur->word_idx = word_idx;
}

class Solution {
public:
    
    // Complexity: O(3 * l)
    // because we at most search 3 branches under this cur(including)
    // and each branch's depth is at most O(l)
    void get_result(TrieNode *cur, vector<string> &res, vector<string> &products){
        if(res.size() == MAX_PROD) return;
        if(cur == nullptr) return;
        if(cur->word_idx != -1) res.push_back(products[cur->word_idx]);

        // preorder traversal, first found first add
        for(int i = 0; i < 26; i++){
            get_result(cur->children[i+'a'], res, products);
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // l = max({products[i].size()})
        int n = searchWord.size();
        int m = products.size();

        TrieNode r;
        TrieNode *root = &r;

        // O(m) * O(l): Each word will take at most O(l) time to be inserted into Trie
        for(int i = 0; i < m; i++){
            add_word(products[i], i, root);
        }

        // O(n) * O(3*l)
        vector<vector<string>> ans(searchWord.size());
        TrieNode *cur = root;
        for(int i = 0; i < searchWord.size(); i++){
            char c = searchWord[i];

            cur = cur->children[c];
            if(cur == nullptr) break;
            // searchWord: [0, i]
            get_result(cur, ans[i], products);
        }
        // Overall:
        // Time: O(ml) + O(nl)
        // Space: O(ml) (Trie) + O(3nl) (output) + O(l) (program stack during dfs)
        return ans;
    }
};
