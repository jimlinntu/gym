using Board = vector<vector<char>>;
class Solution {
private:
    bool grids[9][9]; // grids[grid][num]: whether  exists in 
    bool cols[9][9]; // cols[col][num]
    bool rows[9][9]; // rows[row][num]
public:
    bool check(int num, int x, int y){
        int grid = (x / 3) * 3 + y / 3;
        if(rows[x][num] or cols[y][num] or grids[grid][num]) return false;
        return true;
    }
    void put_num(Board &board, int num, int x, int y){
        int grid = (x / 3) * 3 + y / 3;
        board[x][y] = '1'+num;
        // mark this row (column, grid) has already been occupied by this num
        rows[x][num] = 1;
        cols[y][num] = 1;
        grids[grid][num] = 1;
    }
    void reset_num(Board &board, int num, int x, int y){
        int grid = (x / 3) * 3 + y / 3;
        board[x][y] = '.';
        rows[x][num] = 0;
        cols[y][num] = 0;
        grids[grid][num] = 0;
        return;
    }
    bool fill_board(Board &board, int pos){
        int x = pos / 9, y = pos % 9;
        bool ret;
        if(pos >= 81) return true;
        if(board[x][y] != '.') return fill_board(board, pos+1);

        for(int i = 0; i < 9; i++){
            // if this step is invalid, continue
            if(!check(i, x, y)) continue;
            put_num(board, i, x, y);
            ret = fill_board(board, pos+1);
            if(!ret){
                // erase this character and then move on to the next possible character
                reset_num(board, i, x, y);
            }else return true; // if we successfully find a solution, return it!
        }
        // all numbers are not valid, return false
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        fill(&grids[0][0], &grids[0][0]+sizeof(grids), 0);
        fill(&cols[0][0], &cols[0][0]+sizeof(cols), 0);
        fill(&rows[0][0], &rows[0][0]+sizeof(rows), 0);
        for(int i = 0; i < 81; i++){
            if(board[i/9][i%9] == '.') continue;
            put_num(board, board[i/9][i%9]-'1', i/9, i%9);
        }
        fill_board(board, 0);
        return;
    }
};
