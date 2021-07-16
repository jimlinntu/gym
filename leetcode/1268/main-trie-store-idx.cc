const int MAX_PROD = 3;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<int> indices; // indices[i] point to products

    TrieNode(){
    }
};

void add_word(string &word, int word_idx, TrieNode *root){
    TrieNode *cur = root;
    for(char c: word){
        if(cur->children[c] == nullptr) cur->children[c] = new TrieNode();
        cur = cur->children[c];

        // add this word_idx to this node
        if(cur->indices.size() < MAX_PROD) cur->indices.push_back(word_idx);
    }
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // m = products.size()
        // l = max({products[i].size()})
        // O(m log m) * O(l) (each comparison take at most O(l))
        TrieNode r;
        TrieNode *root = &r;
        sort(products.begin(), products.end());

        // O(m) * O(l): Each word will take at most O(l) time to be inserted into Trie
        for(int i = 0; i < products.size(); i++){
            add_word(products[i], i, root);
        }

        // Each prefix has at most 3 candidates and each candidate is of max length l
        // O(n * (3 * l))
        vector<vector<string>> ans(searchWord.size());
        TrieNode *cur = root;
        for(int i = 0; i < searchWord.size(); i++){
            char c = searchWord[i];
            cur = cur->children[c];
            if(cur == nullptr) break;
            // searchWord: [0, i]
            vector<int> &indices = cur->indices;
            for(int j: indices){
                ans[i].push_back(products[j]);
            }
        }
        // Overall:
        // O(m log m) * O(l) + O(ml) + O(3nl)
        return ans;
    }
};
