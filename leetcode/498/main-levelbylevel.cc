class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> vv(m+n-1);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vv[i+j].push_back(mat[i][j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < m+n-1; i++){
            if(i % 2 == 0) reverse(vv[i].begin(), vv[i].end());
            for(int j = 0; j < vv[i].size(); j++){
                ans.push_back(vv[i][j]);
            }
        }
        return ans;
    }
};
