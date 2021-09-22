class Solution {
public:
    int m,n;
    bool tag_need_crush(vector<vector<int>> &grid){
        // check horizontal
        bool need_crush = false;
        for(int i = 0; i < m; i++){
            int prev_cnt = 0;
            for(int j = 0; j < n; j++){
                if(j == 0 or abs(grid[i][j-1]) == abs(grid[i][j])){
                    // same
                    prev_cnt++;
                }else{
                    // if the number change
                    if(grid[i][j-1] != 0 and prev_cnt >= 3){
                        need_crush = true;
                        // tag it - (but still preserve the number)
                        for(int k = j-prev_cnt; k < j; k++){
                            grid[i][k] = -abs(grid[i][k]);
                        }
                    }
                    // itself
                    prev_cnt = 1;
                }
            }
            if(grid[i][n-1] != 0 and prev_cnt >= 3){
                need_crush = true;
                // tag it -
                for(int k = n-prev_cnt; k < n; k++){
                    grid[i][k] = -abs(grid[i][k]);
                }
            }
        }
        // check vertical
        for(int j = 0; j < n; j++){
            int prev_cnt = 0;
            for(int i = 0; i < m; i++){
                if(i == 0 or abs(grid[i-1][j]) == abs(grid[i][j])){
                    prev_cnt++;
                }else{
                    if(grid[i-1][j] != 0 and prev_cnt >= 3){
                        need_crush = true;
                        // tag -
                        for(int k = i-prev_cnt; k < i; k++){
                            grid[k][j] = -abs(grid[k][j]);
                        }
                    }
                    prev_cnt = 1;
                }
            }
            if(grid[m-1][j] != 0 and prev_cnt >= 3){
                need_crush = true;
                // tag -1
                for(int k = m-prev_cnt; k < m; k++){
                    grid[k][j] = -abs(grid[k][j]);
                }
            }
        }
        return need_crush;
    }
    void compress(vector<vector<int>> &grid){
        // Move each column
        for(int j = 0; j < n; j++){
            int l = m-1, r = m-1;
            // Set negative to zero and move
            // Two pointers (or like color sort)
            for(; r >= 0; r--){
                if(grid[r][j] > 0){
                    swap(grid[r][j], grid[l][j]);
                    l--;
                }else if(grid[r][j] < 0){
                    grid[r][j] = 0;
                }
            }
            for(int i = 0; i < m; i++){
                assert(grid[i][j] >= 0);
            }
        }
    }
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        auto cpboard = board;
        while(true){
            bool r = tag_need_crush(cpboard);
            if(!r) break;
            compress(cpboard);
        }
        return cpboard;
    }
};
