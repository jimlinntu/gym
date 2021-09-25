class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int num_diag = m+n-1;
        vector<int> ans;
        for(int d = 0; d < num_diag; d++){
            int row, col;
            if(d % 2 == 0){
                if(d < m) row = d;
                else row = m-1;

                if(d < m) col = 0;
                else col = d-m+1;
                // bottom to up
                for(;row >= 0 and col < n; row--, col++){
                    ans.push_back(mat[row][col]);
                }
            }else{
                if(d < n) row = 0;
                else row = d-n+1;
                if(d < n) col = d;
                else col = n-1;

                // up to bottom
                for(; row < m and col >= 0; row++, col--){
                    ans.push_back(mat[row][col]);
                }
            }
        }
        return ans;
    }
};
