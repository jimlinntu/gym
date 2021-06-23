struct SparseVec{
    // vec == [(j, val), ...]
    vector<pair<int, int>> vec;
    SparseVec(vector<int> &dense_vec){
        int n = dense_vec.size();
        for(int i = 0; i < n; i++){
            if(dense_vec[i] != 0)
                vec.push_back({i, dense_vec[i]});
        }
    }

    int operator*(const SparseVec &r_vec) const{
        int ln = vec.size(), rn = r_vec.vec.size();
        int l = 0, r = 0;
        int s = 0;
        while(l < ln and r < rn){
            int l_idx, l_val, r_idx, r_val;
            tie(l_idx, l_val) = vec[l];
            tie(r_idx, r_val) = r_vec.vec[r];

            if(l_idx == r_idx){
                s += l_val * r_val;
                l++, r++;
            }else if(l_idx < r_idx){
                l++;
            }else{
                r++;
            }
        }
        return s;
    }
};

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();

        vector<SparseVec> sparse1, sparse2;
        for(int i = 0; i < m; i++){
            sparse1.push_back(SparseVec(mat1[i]));
        }
        vector<int> vec(k);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                vec[j] = mat2[j][i];
            }
            sparse2.push_back(SparseVec(vec));
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans[i][j] = sparse1[i] * sparse2[j];
            }
        }
        return ans;
    }
};
