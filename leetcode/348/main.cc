class TicTacToe {
public:
    /** Initialize your data structure here. */
    int n;
    vector<int> row_count;
    vector<int> col_count;
    int dcount, antidcount;
    TicTacToe(int n) {
        // n rows, n cols, 2 diagonals
        row_count = vector<int>(n, 0);
        col_count = vector<int>(n, 0);
        dcount = antidcount = 0;
        this->n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        // Because the move is gauranteed to be a valid one,
        // we don't have to store the whole board!
        // Player 1: ++
        // Player 2: --
        int win = 0;
        if(player == 1){
            if(++row_count[row] == n) win = 1;
            if(++col_count[col] == n) win = 1;
            if(row == col)
                if(++dcount == n)
                    win = 1;
            if(row+col == n-1)
                if(++antidcount == n)
                    win = 1;
        }else{
            if(--row_count[row] == -n) win = 2;
            if(--col_count[col] == -n) win = 2;
            if(row == col)
                if(--dcount == -n)
                    win = 2;
            if(row+col == n-1)
                if(--antidcount == -n)
                    win = 2;
        }
        return win;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
