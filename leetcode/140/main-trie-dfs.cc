struct TrieNode {
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

void initTrie(TrieNode *root, vector<string> &wordDict){
    TrieNode *cur;
    for(auto &word: wordDict){
        cur = root;
        for(char c: word){
            int i = c2i(c);
            if(cur->children[i] == nullptr) cur->children[i] = new TrieNode();
            cur = cur->children[i];
        }
        cur->is_word = true;
    }
}

void solve(vector<string> &ans, string &s, string &working_str,
           int startidx, vector<bool> &dp, TrieNode *root){
    // [staridx, n) cannot be segmented
    if(!dp[startidx]) return;
    if(startidx == s.size()){
        // append to the answer vector
        ans.push_back(working_str);
        return;
    }
    TrieNode *cur = root;
    string to_add_string;
    for(int i = startidx; i < s.size(); i++){
        cur = cur->children[c2i(s[i])];
        if(cur == nullptr) break;
        if(!cur->is_word) continue;
        // Append
        if(working_str.size() == 0)
            to_add_string = s.substr(startidx, i-startidx+1);
        else
            to_add_string = " " + s.substr(startidx, i-startidx+1);
        working_str += to_add_string;
        solve(ans, s, working_str, i+1, dp, root);
        // Restore: remove to_add_string from working_str
        working_str.resize(working_str.size() - to_add_string.size());
    }
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode root = TrieNode();
        int n = s.size();
        initTrie(&root, wordDict);
        // See 139 for more information about this dp
        vector<bool> dp(n+1, false);
        dp[n] = true;
        TrieNode *cur;
        for(int i = n-1; i >= 0; i--){
            cur = &root;
            for(int j = i; j < n; j++){
                cur = cur->children[c2i(s[j])];
                if(cur == nullptr) break;
                if(!cur->is_word) continue;
                dp[i] = dp[i] || dp[j+1];
            }
        }
        vector<string> ans;
        string working_str;
        solve(ans, s, working_str, 0, dp, &root);
        return ans;
    }
};
