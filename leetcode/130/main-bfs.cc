class Solution {
public:
    const char S = 'S'; // survived
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = S;
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                board[i][n-1] = S;
            }
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = S;
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1, j});
                board[m-1][j] = S;
            }
        }
        // mark all connected O of boundary O to S
        int X, Y, nX, nY;
        while(!q.empty()){
            tie(X, Y) = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                nX = X + dir[i][0], nY = Y + dir[i][1];
                if(nX < 0 or nX >= m or nY < 0 or nY >= n) continue;
                if(board[nX][nY] == 'X') continue;
                if(board[nX][nY] == S) continue;
                board[nX][nY] = S; // mark it as S
                q.push({nX, nY});
            }
        }
        // mark all O into X and S into O
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == S) board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
