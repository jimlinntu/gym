class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // n x n
        // Observe rotate == map element from (i, j) to (j, n-1-i)
        // And observe each "peel" of the matrix is independent from other peels
        
        // Peel swapping
        int n = matrix.size();
        int row_start = 0, row_end = n;
        int col_start = 0, col_end = n;
        while(row_start < row_end and col_start < col_end){
            for(int j = col_start; j < col_end-1; j++){
                int x = row_start, y = j;
                int buffer = matrix[x][y];
                for(int i = 0; i < 4; i++){
                    int next_x = y, next_y = n-1-x;
                    swap(buffer, matrix[next_x][next_y]);
                    x = next_x, y = next_y;
                }
            }
            row_start++, row_end--;
            col_start++, col_end--;
        }
        return;
    }
};
