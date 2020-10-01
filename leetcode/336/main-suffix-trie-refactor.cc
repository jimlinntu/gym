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
    // search from the last (a suffix Trie)
    for(int i = k-1; i >= 0; i--){
        if(isPalin(s, 0, i)){
            // Note: cur has not add a s[i] character step!
            cur->indices.push_back(index);            
        }
        if(cur->childs[s[i]-'a'] == nullptr){
            cur->childs[s[i]-'a'] = new Node();
        }
        // move one step
        cur = cur->childs[s[i]-'a'];
    }
    // suffix = "" + suffix
    // "" is also a palindrome!
    cur->indices.push_back(index);
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
        for(int j = 0; j < k; j++){
            // note: cur has not add w[j] character
            if(cur->index != -1 and cur->index != i and isPalin(w, j, k-1)){
                ans.push_back({i, cur->index});
            }
            if(cur->childs[w[j]-'a'] == nullptr){
                nomatch = true;
                break;
            }
            cur = cur->childs[w[j]-'a'];
        }
        if(nomatch) continue;
        // Note: in the above for loop, we do not consider the word  represent
        // in the for loop below, we are guaranteed:
        // if cur->index != -1, cur->indices must contain cur->index!
        // Therefore, by the for loop below, we still consider cur->index!
        m = cur->indices.size();
        for(int j = 0; j < m; j++){
            if(cur->indices[j] != i){
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
