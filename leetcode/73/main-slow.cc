class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool prev_has_row = false;
        bool cur_has_row = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    cur_has_row = true;
                    // Mark elements above as zeros
                    for(int k = i-1; k >= 0; k--){
                        matrix[k][j] = 0;
                    }
                }else if(i > 0 and matrix[i-1][j] == 0){
                    // Propagate column zero above
                    matrix[i][j] = 0;
                }
            }
            // Mark the previous all zeros
            if(prev_has_row and i > 0) fill(&matrix[i-1][0], &matrix[i-1][0]+n, 0);

            prev_has_row = cur_has_row;
            cur_has_row = false;
        }
        if(prev_has_row) fill(&matrix[m-1][0], &matrix[m-1][0]+n, 0);
    }
};
