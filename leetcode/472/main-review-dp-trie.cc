struct TrieNode{
    bool is_word;
    TrieNode *child[26];
    TrieNode(){
        is_word = false;
        for(int i = 0; i < 26; i++) child[i] = nullptr;
    }
};
// NOTE: add the suffix
void add_word(TrieNode *root, string &w){
    TrieNode *cur = root;
    int len = w.size();

    for(int i = len-1; i >= 0; i--){
        if(cur->child[w[i]-'a'] == nullptr)
            cur->child[w[i]-'a'] = new TrieNode();
        cur = cur->child[w[i]-'a'];
    }
    cur->is_word = true;
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ans;
        // dp[i] represents whether string in [0, i) can be formed 
        // by at least one word in the words
        // dp[w.size()] will have a different definition
        bool dp[1001];
        TrieNode *root = new TrieNode();
        int n = words.size();
        for(int i = 0; i < n; i++){
            string &w = words[i];
            add_word(root, w);
        }
        for(int i = 0; i < n; i++){
            string &w = words[i];
            // An empty string cannot be formed by 2 strings
            if(w == "") continue;
            // [0, w.size()]
            fill(dp, dp+w.size()+1, false);
            // dp[""] = true (base case)
            dp[0] = true;
            // dp[w.size()] need to be treated separately
            for(int j = 1; j < w.size(); j++){
                // dp[j]
                TrieNode *cur = root;
                for(int k = j-1; k >= 0; k--){
                    cur = cur->child[w[k]-'a'];
                    if(cur == nullptr) break;
                    // dp[j] = dp[k] and whether [k, j) can form a word
                    // dp[j] = whether [0, k) and [k, j) can form a word
                    dp[j] = dp[k] and cur->is_word;
                    if(dp[j]) break;
                }
            }
            // dp[w.size()]
            TrieNode *cur = root;
            // Notice: k >= 1 rather than k >= 0
            // Because we don't allow a word composed by itself
            // the problem force only two "shorter" words
            for(int k = (int)w.size()-1; k >= 1; k--){
                cur = cur->child[w[k]-'a'];
                if(cur == nullptr) break;
                dp[w.size()] = dp[k] and cur->is_word;
                if(dp[w.size()]) break;
            }
            if(dp[w.size()])
                ans.push_back(w);
        }
        return ans;
    }
};
