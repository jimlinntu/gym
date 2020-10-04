using Board = vector<vector<char>>;
class Solution {
public:
    bool rows[9][9];
    bool cols[9][9];
    bool grids[9][9];
    bool check(int num, int row, int col, int grid){
        if(rows[row][num] or cols[col][num] or grids[grid][num]) return false;
        return true;
    }
    void place(int num, int row, int col, int grid){
        rows[row][num] = 1;
        cols[col][num] = 1;
        grids[grid][num] = 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(grids, 0, sizeof(grids));
        int row, col, grid, num;
        for(int i = 0; i < 81; i++){
            row = i / 9;
            col = i % 9;
            grid = (row / 3) * 3 + col / 3;
            if(board[row][col] == '.') continue;
            num = board[row][col]-'1';
            if(!check(num, row, col, grid)) return false;
            place(num, row, col, grid);
        }
        return true;
    }
};
