int log2(int x){
    assert(x > 0);
    int X = x;
    int p = 0;
    while((X >>= 1) > 0){
        p++;
    }
    if(x > (1 << p)) p++;
    return p;
}

class NumMatrix {
public:
    int m, n;
    vector<vector<int>> trees;

    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // Make it a power of 2
        m = 1 << log2(m);
        n = 1 << log2(n);
        // tree[0]: dummy
        // tree[1]~tree[n-1]: an inner node stores a 1D segment tree (over column indices)
        trees = vector<vector<int>>(2*m, vector<int>(2*n, 0));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        // Move to the leaf node and then go to its parent
        int dval = val - trees[row+m][col+n];
        for(int i = row+m; i > 0; i /= 2){
            // trees[i] is a 1D segment tree
            // col+n is a leaf node
            for(int j = col+n; j > 0; j /= 2){
                // propagate this information to the parent
                trees[i][j] += dval;
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) {
        int s = 0;
        // O(log m) steps
        // overall: O(log m) * O(log n)
        r1 += m, r2 += m;
        while(r1 <= r2){
            // a right child
            if(r1 % 2 == 1) s += sum_columns(r1++, c1, c2); // O(log n)
            // a left child
            if(r2 % 2 == 0) s += sum_columns(r2--, c1, c2); // O(log n)
            r1 /= 2, r2 /= 2;
        }
        return s;
    }
    
    int sum_columns(int tree_idx, int c1, int c2){
        auto &tree = trees[tree_idx];
        c1 += n, c2 += n;
        int s = 0;
        while(c1 <= c2){
            if(c1 % 2 == 1) s += tree[c1++];
            if(c2 % 2 == 0) s += tree[c2--];
            c1 /= 2, c2 /= 2;
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
