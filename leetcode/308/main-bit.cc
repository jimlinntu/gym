class NumMatrix {
public:
    int m, n;
    vector<vector<int>> mat;
    vector<vector<int>> bit2d;
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        m = matrix.size();
        n = matrix[0].size();
        bit2d = vector<vector<int>>(m+1, vector<int>(n+1, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                _update(i+1, j+1, matrix[i][j]);
            }
        }
    }

    // 1-index
    void _update(int i, int j, int v){
        // propgate information to the higher indices
        for(int I = i; I <= m; I += I & (-I)){
            for(int J = j; J <= n; J += J & (-J)){
                bit2d[I][J] += v;
            }
        }
    }

    // 1-index
    int _query(int i, int j){
        // get the information from the lower indices
        int s = 0;
        for(int I = i; I > 0; I -= I & (-I)){
            for(int J = j; J > 0; J -= J & (-J)){
                s += bit2d[I][J];
            }
        }
        return s;
    }

    void update(int row, int col, int val) {
        _update(row+1, col+1, val-mat[row][col]);
        mat[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // D - A - B + C
        row1++, col1++, row2++, col2++;
        int D = _query(row2, col2);
        int C = _query(row1-1, col1-1);

        int A = _query(row1-1, col2);
        int B = _query(row2, col1-1);
        return D - A - B + C;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
