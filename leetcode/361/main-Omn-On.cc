class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        // Naive: O(m n) * O(m+n)
        int m = grid.size();
        int n = grid[0].size();
        int row_kill = 0;
        vector<int> col_kill(n, 0);
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // Ex. 0 E E E W 0 E E E
                //     ^         ^      <------ we only compute row_kill at these places
                if(j == 0 or grid[i][j-1] == 'W'){
                    row_kill = 0;
                    // compute row_kill
                    for(int k = j; k < n and grid[i][k] != 'W'; k++){
                        row_kill += grid[i][k] == 'E';
                    }
                }
                if(i == 0 or grid[i-1][j] == 'W'){
                    col_kill[j] = 0;
                    // compute col_kill
                    for(int k = i; k < m and grid[k][j] != 'W'; k++){
                        col_kill[j] += grid[k][j] == 'E';
                    }
                }
                if(grid[i][j] == '0')
                    ans = max(ans, row_kill + col_kill[j]);
            }
        }
        return ans;
    }
};
