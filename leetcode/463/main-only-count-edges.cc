class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    bool has_edge(int x, int y, int d, vector<vector<int>> &grid){
        int nx = x + dir[d][0], ny = y + dir[d][1];
        int count = island(x, y, grid) + island(nx, ny, grid);
        // land to water
        if(count == 1) return true;
        // land to land or water to water
        return false;
    }
    // handle edge cases
    bool island(int x, int y, vector<vector<int>> &grid){
        // water
        if(x < 0 or x >= m or y < 0 or y >= n) return false;
        return grid[x][y];
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) continue;
                // check 4 directions
                for(int d = 0; d < 4; d++){
                    // The edge of (i, j) with direction `d`
                    if(!has_edge(i, j, d, grid)) continue;
                    // has edge, but we need to check whether it is connected
                    // to the previous edge before
                    ans++;
                    if(d < 2){
                        // up edge or down edge
                        // Ex.
                        // 000
                        // 110
                        // 000
                        // check left, if there is already an edge
                        // we will not count this edge!
                        if(island(i, j-1, grid) and has_edge(i, j-1, d, grid))
                            ans--;
                    }else{
                        if(island(i-1, j, grid) and has_edge(i-1, j, d, grid))
                            ans--;
                    }
                }
                
            }
        }
        return ans;
    }
};
