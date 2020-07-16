int char2idx(char c){
    return c - 'a';
}
struct Node{
    char c; // this node's character value
    bool isend; // whether this node is an ending node
    Node *children[26]; // [a-z] children
    string s; // the full string
    Node(){
        c = 0;
        isend = false;
        fill_n(children, 26, nullptr);
    }
    Node(char c, bool isend, string &s){
        this->c = c;
        this->isend = isend;
        // only save this when this is an ending node,
        // otherwise just leave the string empty
        if(isend) this->s = s;
        fill_n(children, 26, nullptr);
    }
    void update_isend(string &s){
        this->isend = true;
        this->s = s;
    }
    ~Node(){
        for(int i = 0; i < 26; i++){
            if(children[i] != nullptr) delete children[i];
        }
    }
};
class Solution {
public:
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    void build_trie(vector<string> &words, Node *root){
        // O(# words * the max length of words)
        int n;
        Node *cur;
        for(auto &word: words){
            // starting from the root
            cur = root;
            n = word.size();
            for(int i = 0; i < n; i++){
                char c = word[i];
                int idx = char2idx(c);
                if(cur->children[idx] == nullptr){
                    // This character has not appeared under this cur before
                    cur->children[idx] = new Node(c, i == n-1, word);
                }else if(i == n-1){
                    // this prefix can form a word
                    cur->children[idx]->update_isend(word);
                }
                // move to the next child
                cur = cur->children[idx];
            }
        }
    }
    void traverse(vector<vector<char>> &board,
                  int m, int n, int x, int y,
                  Node* cur, vector<string> &ans){
        char c = board[x][y];
        Node *next = cur->children[char2idx(c)];
        if(next == nullptr) return; // no character here
        if(next->isend){
            next->isend = false; // reset isend to avoid duplicate answers
            ans.push_back(next->s);
        }

        board[x][y] = 0; // set this as visited
        // up, down, left, right
        for(auto &dir: dirs){
            int i = dir[0], j = dir[1];
            int xx = x+i, yy = y+j;
            // out-of-board, ignore it
            if(!(0 <= xx and xx < m and 0 <= yy and yy < n)) continue;
            // have already been visited
            if(board[xx][yy] == 0) continue;
            traverse(board, m, n, xx, yy, next, ans);    
        }
        board[x][y] = c; // restore its original character
        return;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int m = board.size();
        if(m == 0) return ans;
        int n = board[0].size();
        Node *root = new Node(); // a dummy root
        build_trie(words, root);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // starting from different position on the board
                traverse(board, m, n, i, j, root, ans);
            }
        }
        // clear root's subtree and itself
        delete root;
        return ans;
    }
};
