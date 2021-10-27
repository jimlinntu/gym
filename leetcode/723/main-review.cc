class Solution {
public:
    int m, n;
    bool crush(vector<vector<int>> &board){
        bool need_crush = false;
        // Check row
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int k = j;
                while(k < n and board[i][j] == board[i][k]) k++;
                if(k - j < 3) continue;
                if(board[i][j] == 0) continue;
                for(int p = j; p < k; p++)
                    // tag it negative
                    board[i][p] = -board[i][p];
                j = k-1; // fast foward
                need_crush = true;
            }
        }
        
        // Check col
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                int k = i;
                while(k < m and abs(board[i][j]) == abs(board[k][j])) k++;
                if(k - i < 3) continue;
                if(board[i][j] == 0) continue;
                for(int p = i; p < k; p++)
                    board[p][j] = -abs(board[p][j]);
                i = k-1; // fast foward
                need_crush = true;
            }
        }
        
        // Eliminate the candy column by column
        for(int j = 0; j < n; j++){
            int cur = m-1;
            // Apply color sorting in one pass
            for(int i = m-1; i >= 0; i--){
                if(board[i][j] > 0){
                    swap(board[cur][j], board[i][j]);
                    cur--;
                }else if(board[i][j] < 0){
                    board[i][j] = 0;
                }
            }
        }

        return need_crush;
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        while(crush(board)){
        }
        return board;
    }
};
