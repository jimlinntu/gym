class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();

        vector<vector<pair<int, int>>> sparse(m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < k; j++){
                if(mat1[i][j] != 0) sparse[i].push_back({j, mat1[i][j]});
            }
        }
        
        // Multiply sparse with mat2
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
           for(int j = 0; j < n; j++){
               for(int k = 0; k < sparse[i].size(); k++){
                   int idx, val;
                   tie(idx, val) = sparse[i][k];
                   ans[i][j] += val * mat2[idx][j];
               }
           }
        }
        
        return ans;
    }
};
