struct Node{
    Node *childs[26]; // a-z
    // if index == -1, it means this cannot form a word
    // otherwise, words[index] == this word
    int index;
    vector<int> indices;
    Node(){
        index = -1;
        for(int i = 0; i < 26; i++){
            childs[i] = nullptr;
        }
    }
    ~Node(){
        for(int i = 0; i < 26; i++){
            if(childs[i]) delete childs[i];
        }
        return;
    }
};

bool isPalin(string &s, int l, int r){
    // check if s[l:r] is a palindrome (boundaries inclusive)
    while(l < r and s[l] == s[r]){
        l++, r--;
    }
    // l >= r, we can know s[l:r] is a palindrome
    return l >= r;
}

void addWord(Node *root, string &s, int index){
    // O(k^2): for each suffix, we will need to check if its prefix is a palindrome
    Node *cur = root;
    int k = s.length();
    // Do not forget "" is a suffix of s
    if(isPalin(s, 0, k-1)){
        cur->indices.push_back(index);
    }
    // search from the last (a suffix Trie)
    for(int i = k-1; i >= 0; i--){
        // suffix == s[i:k-1]
        char c = s[i];
        int idx = c - 'a';
        if(cur->childs[idx] == nullptr){
            cur->childs[idx] = new Node();
        }
        cur = cur->childs[idx];
        // s = prefix (the rest of this word) + suffix (corresponding to this Node)
        // if prefix can form a palindrome, we add it into the indices of this node
        // Note: isPalin(s, 0, -1) == true because this indicates the empty string
        if(isPalin(s, 0, i-1)){
            cur->indices.push_back(index);
        }
    }
    // record this node as a valid word
    cur->index = index;
}

// O(n k^2)
void buildSuffixTrie(Node *root, vector<string> &words){
    int n = words.size();
    for(int i = 0; i < n; i++){
        // add this word into the suffix Trie
        addWord(root, words[i], i);
    }
}

void search(Node *root, vector<string> &words, vector<vector<int>> &ans){
    int n = words.size();
    int k, m;
    Node *cur;

    // loop over each word
    for(int i = 0; i < n; i++){
        string &w = words[i];
        k = w.length();
        bool nomatch = false;
        cur = root;
        // Consider prefix == ""
        if(cur->index != -1 and cur->index != i and isPalin(w, 0, k-1)){
            ans.push_back({i, cur->index});
        }
        // w = prefix + w[j+1:k-1] where
        //     prefix == w[0:j] (inclusive)
        for(int j = 0; j < k; j++){
            // if we cannot find a suffix match, we are sure this word
            // has no other words in the words can be appended to form a palin
            if(cur->childs[w[j]-'a'] == nullptr){
                nomatch = true;
                break;
            }
            cur = cur->childs[w[j]-'a'];
            // if this suffix exists in the words and w[j+1:k-1] is a palin
            if(cur->index != -1 and cur->index != i and isPalin(w, j+1, k-1)){
                // Case 1:
                // words[i] + words[cur->index] can form a palin
                // because:
                //     words[i] = prefix + w[j+1:k-1]
                //     words[cur->index] = suffix
                //     and prefix == suffix
                ans.push_back({i, cur->index});
            }
        }
        // there is no word in the words can append after this word
        // and form a palin
        if(nomatch) continue;

        m = cur->indices.size();
        for(int j = 0; j < m; j++){
            // Case 2:
            // words[i] + words[cur->indices[j]] can form a palin
            // because:
            //     words[i] = prefix
            //     words[...] = the_rest(is a palin) + suffix
            //     and prefix == suffix
            
            // Note: suffix == "" + suffix, and "" must be a palindrome
            // so if a Node's cur->index != -1, its cur->indices must contain itself!
            // By guarding this push_back by cur->indices[j] != cur->index,
            // we can avoid duplicates
            if(cur->indices[j] != i and cur->indices[j] != cur->index){
                ans.push_back({i, cur->indices[j]});
            }
        }
    }
    return;
}

class Solution {
public:    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        Node *root = new Node();
        buildSuffixTrie(root, words);
        search(root, words, ans);
        delete root;
        return ans;
    }
};
