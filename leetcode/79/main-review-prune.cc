class Solution {
public:
    int m,n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int remain_count;

    bool visited[6][6] = {false};
    unordered_map<char, int> word_freq;
    unordered_map<char, int> board_freq;

    bool search(int x, int y, vector<vector<char>> &board,
                string &word, int i){
        if(i >= word.size()) return true;
        // 1. No enough characters
        if(remain_count < word.size() - i) return false;
        if(x < 0 or x >= m or y < 0 or y >= n) return false;
        if(visited[x][y]) return false; // Cycle
        if(board[x][y] != word[i]) return false;
        // 2. if there exists a character no enough, return
        for(auto it = word_freq.begin(); it != word_freq.end(); it++){
            char c = it->first;
            int count = it->second;
            
            // don't contain this char
            if(board_freq.count(c) == 0) return false;
            
            // no enough characters
            if(board_freq[c] < count) return false;
        }

        visited[x][y] = true;
        remain_count--;
        board_freq[board[x][y]]--;
        word_freq[board[x][y]]--;

        for(int d = 0; d < 4; d++){
            int next_x = x + dir[d][0], next_y = y + dir[d][1];
            if(search(next_x, next_y, board, word, i+1)) return true;
        }

        visited[x][y] = false;
        remain_count++;
        board_freq[board[x][y]]++;
        word_freq[board[x][y]]++;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        remain_count = m*n;

        for(char c: word) word_freq[c]++;
        for(auto &v: board)
            for(char c: v)
                board_freq[c]++;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(search(i, j, board, word, 0)) return true;
            }
        }
        return false;
    }
};
