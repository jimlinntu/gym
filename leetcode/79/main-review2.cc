class Solution {
public:
    int m,n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[6][6];

    bool search(int x, int y, vector<vector<char>> &board,
                string &word, int i){
        if(i >= word.size()) return true;
        if(x < 0 or x >= m or y < 0 or y >= n) return false;
        if(visited[x][y]) return false; // Cycle
        if(board[x][y] != word[i]) return false;

        visited[x][y] = true;
        for(int d = 0; d < 4; d++){
            int next_x = x + dir[d][0], next_y = y + dir[d][1];
            if(search(next_x, next_y, board, word, i+1)) return true;
        }
        visited[x][y] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(search(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};
