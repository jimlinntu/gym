class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int anchor_i = -1, anchor_j = -1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0 and anchor_i == -1){
                    anchor_i = i, anchor_j = j;
                }
                if(matrix[i][j] == 0){
                    // Use matrix[anchor_i][anchor_j]'s row and col
                    matrix[anchor_i][j] = 0;
                    matrix[i][anchor_j] = 0;
                }
            }
        }
        if(anchor_i == -1) return;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == anchor_i or j == anchor_j) continue;
                if(matrix[anchor_i][j] == 0 or matrix[i][anchor_j] == 0)
                    matrix[i][j] = 0;
            }
        }
        // Mark row anchor_i and col anchor_j as zero
        for(int i = 0; i < m; i++){
            matrix[i][anchor_j] = 0;
        }
        for(int j = 0; j < n; j++){
            matrix[anchor_i][j] = 0;
        }
    }
};
