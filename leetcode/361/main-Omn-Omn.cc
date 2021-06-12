class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        // Naive: O(m n) * O(m+n)
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n, -1));
        vector<vector<int>> col(m, vector<int>(n, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0, k; j < n; j = k){
                // Two pointers
                int sum = grid[i][j] == 'E';
                for(k = j+1; k < n and grid[i][k] != 'W'; k++){
                    sum += grid[i][k] == 'E';
                }
                for(int kk = j; kk < k; kk++){
                    // the enemy we can kill in this row if we place the bomb
                    // on (i, kk)
                    // NOTE: we here assume we can place the bomb on the enemy
                    //       it will not affect our solution
                    row[i][kk] = sum;
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int i = 0, k; i < m; i = k){
                int sum = grid[i][j] == 'E';
                for(k = i+1; k < m and grid[k][j] != 'W'; k++){
                    sum += grid[k][j] == 'E';
                }
                for(int kk = i; kk < k; kk++){
                    col[kk][j] = sum;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != '0') continue;
                assert(row[i][j] != -1 and col[i][j] != -1);
                ans = max(ans, row[i][j] + col[i][j]);
            }
        }
        return ans;
    }
};
