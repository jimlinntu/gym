class Solution {
public:
    pair<int, int> next(int i, int j, int n){
        return {j, n-1-i};
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid = n/2;
        // row
        for(int i = 0; i < mid; i++){
            // col
            for(int j = i; j < n-i-1; j++){
                // Swap three times
                // Ex. 4 8 -> 8 4 -> 6 4 -> 3 4
                //     3 6    3 6    3 8    6 8
                // 
                int ii = i, jj = j;
                for(int k = 0; k < 3; k++){
                    tie(ii, jj) = next(ii, jj, n);
                    swap(matrix[i][j], matrix[ii][jj]);
                }
            }
        }
    }
};
