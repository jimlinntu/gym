class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // n x n
        // Observe rotate == map element from (i, j) to (j, n-1-i)
        // First, (i, j) -> (j, i)
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // map (j, i) to (j, n-1-i)
        for(int j = 0; j < n; j++){
            // i swap with n-i
            // NOTE: n is odd: 0 1 2
            for(int i = 0; i < n/2; i++){
                swap(matrix[j][i], matrix[j][n-1-i]);
            }
        }
        return;
    }
};
