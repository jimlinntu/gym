class Solution {
public:
    int n;
    // O(n) finding # of elements <= x within this matrix
    int count_leq(vector<vector<int>> &matrix, int x){
        int c = 0;
        // Starting from (n-1, 0)
        int row = n-1;
        for(int col = 0; col < n; col++){
            // Walk until x >= matrix[row][col]
            while(0 <= row and x < matrix[row][col]){
                row--;
            }
            if(row == -1) break;
            c += row+1;
        }
        return c;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        // [l == min, r == max]
        int l = matrix[0][0], r = matrix.back().back();
        while(l <= r){
            int mid = (l + r) / 2;
            int c = count_leq(matrix, mid);
            if(c >= k) r = mid-1;
            else l = mid+1;
        }
        return l;
    }
};
