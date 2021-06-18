class Solution {
public:
    int m, n;
    pair<int, int> reindex(int i){
        return {i / n, i % n}; // map this index to (row, col)
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();
        // Flatten the matrix virtually
        int N = m*n;
        int l = 0, r = N;
        int x, y;
        while(l < r){
            int mid = (l+r)/2;
            tie(x, y) = reindex(mid);
            int v = matrix[x][y];
            if(target <= v){
                // [l, mid)
                r = mid;
            }else{
                // [mid+1, r)
                l = mid+1;
            }
        }
        tie(x, y) = reindex(l);
        // if l == N, then return false
        return (l != N) and matrix[x][y] == target;
    }
};
