class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    // check 4 directions
                    for(int d = 0; d < 4; d++){
                        int x = i + dir[d][0], y = j + dir[d][1];
                        if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y] == 0){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
