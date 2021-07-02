struct TrieNode {
    int word_idx;
    // if a word has the current suffix and its prefix is a palindrome, we record this
    // index
    vector<int> indices;
    TrieNode *child[26];
    TrieNode(): word_idx(-1){
        fill(child, child+26, nullptr);
    }
    ~TrieNode(){
        for(int i = 0; i < 26; i++){
            if(child[i]) delete child[i];
        }
    }
};


bool isP(string &s, int start, int end){
    if(s.size() == 0) return true;
    int l = start, r = end;
    while(l <= r and s[l] == s[r]){
        l++, r--;
    }
    return l > r; // if l > r, then this is a palindrome
}

void add(TrieNode *root, string &w, int idx){
    TrieNode *cur = root;
    int len = w.size();
    for(int i = len-1; i >= 0; i--){
        // check if w[0~i] is a palindrome
        if(isP(w, 0, i)) cur->indices.push_back(idx);

        char c = w[i];
        if(cur->child[c-'a'] == nullptr)
            cur->child[c-'a'] = new TrieNode();
        cur = cur->child[c-'a'];
    }

    assert(cur->word_idx == -1); // assert the uniqueness of w
    // NOTE: "" is a valid prefix palindrome for w
    cur->word_idx = idx;
    cur->indices.push_back(idx);
}


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode r;
        TrieNode *root = &r; // this r will be destroyed automatcially

        int n = words.size();

        for(int i = 0; i < n; i++){
            add(root, words[i], i);
        }

        vector<vector<int>> ans;
        // O(n k^2), k == max length of a word
        for(int i = 0; i < n; i++){
            // Find a r s.t. w + r is a palindrome
            // Case 1&2:
            // len(r) < len(w)
            // Case 3:
            // len(r) >= len(w)
            auto &w = words[i];
            int len_w = w.size();
            TrieNode *cur = root;

            for(int j = 0; j < len_w; j++){
                // Case 2: len(r) < len(w) and w + r is a palindrome
                // if the middle part is a palindrome and we can find the right word
                if(cur->word_idx != -1 and cur->word_idx != i and
                        isP(w, j, len_w-1))
                    ans.push_back({i, cur->word_idx});
                // move on
                cur = cur->child[w[j]-'a'];
                if(cur == nullptr) break;
            }
            // if cur == nullptr then we cannot find a r
            // s.t. Case 3 is satisfied
            if(cur == nullptr) continue;
            // Case 3: len(r) >= len(w)
            auto &indices = cur->indices;
            // NOTE: indices include "" prefix
            // e.g. abcd + dcba is checked in this part
            for(int j: indices){
                if(i == j) continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};
