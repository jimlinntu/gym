class Solution {
public:
    // Represent each cell using two bits
    // 00, 01, 10, 11
    // 00: 0 -> 0
    // 01: 1 -> 0
    // 10: 0 -> 1
    // 11: 1 -> 1
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int s = 0;
                for(int dx = -1; dx <= 1; dx++){
                    for(int dy = -1; dy <= 1; dy++){
                        if(dx == 0 and dy == 0) continue;
                        int x = i + dx, y = j + dy;
                        if(x < 0 or x >= m or y < 0 or y >= n) continue;
                        s += board[x][y] & 1;
                    }
                }
                // Live cell
                if((board[i][j] & 1)){
                    if(s == 2 or s == 3) board[i][j] |= 0b10;
                }else{
                    // Dead cell
                    if(s == 3) board[i][j] |= 0b10;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] >>= 1; // use the second bit
            }
        }
    }
};
