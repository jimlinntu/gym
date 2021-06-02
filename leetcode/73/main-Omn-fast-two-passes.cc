class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // NOTE: matrix[0][0] should be confusing,
        //       We use another variable to tell whether
        // After adding an addition variable, matrix[0][0] now only represents
        // whether row 0 should be placed zeros
        bool set_first_col = false;
        for(int i = 0; i < m; i++){
            // Take care of the first column
            if(matrix[i][0] == 0) set_first_col = true;
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    // use the first row and first column as markers
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 1; j--){
                if(matrix[0][j] == 0 or matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
            if(set_first_col) matrix[i][0] = 0;
        }
    }
};
