class Solution {
public:
    int m, n;
    // up, down, left, right
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool dfs(int x, int y,
            vector<vector<char>> &grid, vector<vector<bool>> &visited){
        if(x < 0 or x >= m) return false;
        if(y < 0 or y >= n) return false;
        if(grid[x][y] == '0') return false;
        if(visited[x][y]) return false;
        visited[x][y] = true;
        for(int i = 0; i < 4; i++){
            dfs(x + d[i][0], y + d[i][1], grid, visited);
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int num_islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // O(mn) because each grid will only be walked at most twice
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                num_islands += dfs(i, j, grid, visited);
            }
        }
        return num_islands;
    }
};
