class Solution {
public:
    int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // The reason why we can perform a DP-style DFS is because
    // there is no loop in this directed graph
    // Because if a -> b -> c -> d -> a
    // then a < b < c < d < a which is impossible
    int dfs(int x, int y, vector<pair<int, int>> g[200][200], int depth[200][200]){
        // Cache the result
        if(depth[x][y] != -1) return depth[x][y];

        int max_depth = 1; // itself
        // Find out the depth of its neighbor
        for(auto &p: g[x][y]){
            max_depth = max(max_depth, 1+dfs(p.first, p.second, g, depth));
        }
        return (depth[x][y] = max_depth);
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // g[i][j] = {(x, y) where matrix[i][j] < matrix[x][y]}
        vector<pair<int, int>> g[200][200];

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int d = 0; d < 4; d++){
                    int x = i + dir[d][0], y = j + dir[d][1];
                    if(x < 0 or x >= m or y < 0 or y >= n) continue;
                    // Build an edge: u->v if u < v
                    if(matrix[i][j] < matrix[x][y]){
                        g[i][j].push_back({x, y});
                    }
                }
            }
        }
        int depth[200][200];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                depth[i][j] = -1;
            }
        }
        int max_depth = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                max_depth = max(max_depth, dfs(i, j, g, depth));
            }
        }
        return max_depth;
    }
};
