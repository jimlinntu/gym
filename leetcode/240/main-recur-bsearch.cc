class Solution {
public:
    bool search(vector<vector<int>> &mat, int t,
               int row_start, int row_end,
               int col_start, int col_end){
        // Complexity:
        // T(n) = 3 * T(n/2) + O(1)
        // T(n) = O(1) + O(3) + .... (depth is log 4 n)
        //      = 1 * (3 ^ (log 4 n) - 1 / (3-1) = O(n ^ (log4 3))
        // Empty regions
        if(row_start >= row_end) return false;
        if(col_start >= col_end) return false;

        int row_mid = (row_start + row_end) / 2;
        int col_mid = (col_start + col_end) / 2;
        int mid_val = mat[row_mid][col_mid];

        if(t == mid_val) return true;
        else if(t < mid_val){
            // down right porition is impossible to contain a target value
            // Because every value inside that region should be >= mid_val
            if(search(mat, t, row_start, row_mid, col_start, col_end)) return true;
            if(search(mat, t, row_mid, row_end, col_start, col_mid)) return true;
        }else{
            // up left portion is impossible to contain a target value
            // Because every value inside that region should be <= mid_val
            if(search(mat, t, row_mid+1, row_end, col_start, col_end)) return true;
            if(search(mat, t, row_start, row_end, col_mid+1, col_end)) return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row_start = 0, row_end = m;
        int col_start = 0, col_end = n;
        return search(matrix, target, 0, m, 0, n);
    }
};
