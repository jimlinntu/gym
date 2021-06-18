class Solution {
public:
    int t;
    bool bsearch(vector<vector<int>> &m,
                 int row_start, int row_end,
                 int col_start, int col_end){
        // [row_start, row_end)
        // [col_start, col_end)
        if(row_start >= row_end) return false;
        if(col_start >= col_end) return false;
        int row_mid = (row_start + row_end) / 2;
        int col_mid = (col_start + col_end) / 2;
        int v = m[row_mid][col_mid];
        if(v == t) return true;
        if(t < v){
            // 1. same row: [row_mid, row_mid+1), [col_start, col_mid)
            // 2. above:    [row_start, row_mid), [col_start, col_end)
            return bsearch(m, row_mid, row_mid+1, col_start, col_mid)
                   || bsearch(m, row_start, row_mid, col_start, col_end);
        }else{
            // 1. same row: [row_mid, row_mid+1), [col_mid+1, col_end)
            // 2. above:    [row_mid+1, row_end), [col_start, col_end)
            return bsearch(m, row_mid, row_mid+1, col_mid+1, col_end)
                   || bsearch(m, row_mid+1, row_end, col_start, col_end);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        t = target;
        return bsearch(matrix, 0, m, 0, n);
    }
};
