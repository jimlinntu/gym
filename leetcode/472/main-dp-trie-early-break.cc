struct TrieNode{
    TrieNode *children[26];
    bool is_word;
    TrieNode(){
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        is_word = false;
    }
    ~TrieNode(){
        for(int i = 0; i < 26; i++){
            if(children[i] != nullptr) delete children[i];
        }
    }
};

constexpr int c2i(char c){
    return c-'a';
}

void initTrie(vector<string> &words, TrieNode *root){
    TrieNode *cur;
    for(auto &word: words){
        cur = root;
        for(char c: word){
            int i = c2i(c);
            if(cur->children[i] == nullptr) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->is_word = true;
    }
}

class Solution {
public:
    bool is_concat(string &word, bool dp[], TrieNode *root){
        int n = word.size();
        // Edge case: ""
        if(n == 0) return false;
        // See 139 solution for more info.
        TrieNode *cur;
        fill(dp, dp+n, false);
        dp[n] = true;
        // O(len(word) * )
        for(int i = n-1; i >= 0; i--){
            cur = root;
            for(int j = i; j < n; j++){
                cur = cur->children[c2i(word[j])];
                if(cur == nullptr) break;
                if(!cur->is_word) continue;
                // Because of "at least two shorter words" constraint
                if(i == 0 and j == n-1) break;
                dp[i] = dp[i] or dp[j+1];
                if(dp[i]) break; // already can form a word
            }
        }
        return dp[0];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        bool dp[1001];
        TrieNode root;
        initTrie(words, &root);
        vector<string> ans;
        for(auto &word: words){
            if(is_concat(word, dp, &root)) ans.push_back(word);
        }
        return ans;
    }
};
