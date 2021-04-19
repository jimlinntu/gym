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

constexpr int char2idx(char c){
    return c-'a';
}

void initTrie(vector<string> &wordDict, TrieNode *root){
    TrieNode *cur;
    for(auto &word: wordDict){
        cur = root;
        for(char c: word){
            if(cur->children[char2idx(c)] == nullptr)
                cur->children[char2idx(c)] = new TrieNode();
            cur = cur->children[char2idx(c)]; // move to that node
        }
        // tag it as a word
        cur->is_word = true;
    }
}
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode root = TrieNode();
        initTrie(wordDict, &root);
        int n = s.size();
        if(n == 0) return true;
        // dp[i] == if [i, n) can be segmented by wordDict
        // dp[n] == if [n, n) can be segmented by wordDict, which is true
        // dp[i] == ([i, j] can form a word) + dp[j+1]
        vector<bool> dp(n+1);
        // Base case:
        dp[n] = true;
        // DP step
        TrieNode *cur;
        char c;
        for(int i = n-1; i >= 0; i--){
            cur = &root;
            for(int j = i; j < n; j++){
                c = s[j];
                cur = cur->children[char2idx(c)];
                if(cur == nullptr) break; // [i, k >= j] cannot form a word
                if(!cur->is_word) continue;
                dp[i] = dp[i] or dp[j+1];
            }
        }
        return dp[0]; // whether [0, n) can form a word
    }
};
