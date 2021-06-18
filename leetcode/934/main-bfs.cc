class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool is_invalid(int x, int y){
        return x < 0 or x >= m or y < 0 or y >= n;
    }
    pair<int, int> find_start(vector<vector<int>> &grid){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    return {i, j};
                }
            }
        }
        assert(false);
        return {-1, -1};
    }
    void collect_first_island(
        vector<vector<int>> &grid, vector<vector<bool>> &visited,
        vector<vector<int>> &points){
        int x, y;
        tie(x, y) = find_start(grid);
        
        queue<pair<int, int>> q;
        visited[x][y] = true;
        q.push({x, y});
        points.push_back({x, y});

        while(!q.empty()){
            int X, Y;
            tie(X, Y) = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int next_x = X + dir[i][0];
                int next_y = Y + dir[i][1];
                if(is_invalid(next_x, next_y)) continue;
                if(visited[next_x][next_y]) continue;
                if(grid[next_x][next_y] == 0) continue;
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
                points.push_back({next_x, next_y});
            }
        }
        return;
    }

    int find_bridge(vector<vector<int>> &grid,
                    vector<vector<bool>> &visited,
                    vector<vector<int>> &points){
        queue<vector<int>> q;
        for(auto &p: points){
            q.push(p);
        }
        int dist = 0;
        while(!q.empty()){
            // Expand boundary (NOTE: 1 surrounded by 1 will not be expanded)
            for(int i = q.size()-1; i >= 0; i--){
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                for(int d = 0; d < 4; d++){
                    int xx = x + dir[d][0], yy = y + dir[d][1];
                    if(is_invalid(xx, yy)) continue;
                    if(visited[xx][yy]) continue;
                    // We have found the other island
                    if(grid[xx][yy]) return dist;
                    visited[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
            dist++;
        }
        // if there is no other island, we will reach here
        assert(false);
        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> points;
        collect_first_island(grid, visited, points);
        return find_bridge(grid, visited, points);
    }
};
