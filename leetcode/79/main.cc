class Solution {
public:
    int m, n;
    bool search(vector<vector<char>> &board, int x, int y, string &word, int w_i){
        // the word is found
        if(w_i >= word.size()) return true;
        // out-of-bound
        if(!(0 <= x and x < m and 0 <= y and y < n)) return false;
        if(board[x][y] != word[w_i]) return false;
        // already visited
        if(board[x][y] == 0) return false;
        char c = board[x][y];
        board[x][y] = 0; // set this position visited
        bool found = false;
        // search horizontally
        for(int i = -1; i < 3 && !found; i += 2){
            found |= search(board, x, y+i, word, w_i+1);
        }
        // search vertically
        for(int i = -1; i < 3 && !found; i += 2){
            found |= search(board, x+i, y, word, w_i+1);
        }
        board[x][y] = c;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        if(m == 0) return false;
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(search(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
