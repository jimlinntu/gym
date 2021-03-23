class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        // Assume we can only load up to row_len
        const int row_len = 2;
        vector<int> row(row_len);
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 1; i < m; i++){
            int num_blocks = n / row_len + (int)(n % row_len != 0);
            for(int j = 0; j < num_blocks; j++){
                int start = j*row_len;
                int len = min(row_len, n-start);
                // Emulate moving numbers from disk to memory
                for(int k = 0; k < len; k++){
                    row[k] = matrix[i][start+k];
                }
                // Compare to the previous row
                for(int k = 0, kk; k < len; k++){
                    kk = start+k-1;
                    // Assume matrix[i-1][kk] is loaded from the disk (constant space)
                    if(kk >= 0 and row[k] != matrix[i-1][kk]) return false;
                }
            }
        }
        return true;
    }
};
