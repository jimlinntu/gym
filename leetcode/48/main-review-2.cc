class Solution {
public:
    pair<int, int> next(int x, int y, int n){
        return {y, n-1-x};
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // (i, j) -> (j, n-1-i)
        // * * * * *
        // * * * * *
        // * * * * *
        // * * * * *
        // * * * * *
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n-i-1; j++){
                int buf = matrix[i][j];
                int x = i, y = j;
                for(int k = 0; k < 4; k++){
                    tie(x, y) = next(x, y, n);
                    swap(buf, matrix[x][y]);
                }
            }
        }
        return;
    }
};
