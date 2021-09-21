class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    // whether (x, y) has an edge on the direction of d
    // NOTE: grid[x][y] must be land
    bool has_edge(int x, int y, int d, vector<vector<int>> &grid){
        if(island(x, y, grid) and !island(x+dir[d][0], y+dir[d][1], grid)) return true;
        return false;
    }
    bool island(int x, int y, vector<vector<int>> &grid){
        if(x < 0 or x >= m or y < 0 or y >= n) return false;
        return grid[x][y];
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        // Check each direction's edge
        // up and bottom
        for(int d = 0; d < 2; d++){
            for(int i = 0; i < m; i++){
                bool prev_edge = false;
                for(int j = 0; j < n; j++){
                    bool edge = has_edge(i, j, d, grid);

                    // if prev_edge == true, we don't count this one
                    if(edge and !prev_edge){
                        ans++;
                    }
                    prev_edge = edge;
                }
            }
        }
        for(int d = 2; d < 4; d++){
            // Loop over columns
            for(int j = 0; j < n; j++){
                bool prev_edge = false;
                for(int i = 0; i < m; i++){
                    bool edge = has_edge(i, j, d, grid);

                    // if prev_edge == true, we don't count this one
                    if(edge and !prev_edge){
                        ans++;
                    }
                    prev_edge = edge;
                }
            }
        }
        return ans;
    }
};
