
class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int bfs(vector<vector<int>> &grid, int x, int y,
            unordered_set<int> buildings, int ub){

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        q.push({x, y, 0});
        visited[x][y] = true;
        int min_dist = 0;

        while(!q.empty() and !buildings.empty() and min_dist < ub){
            int cur_x, cur_y, dist;
            tie(cur_x, cur_y, dist) = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int new_x = cur_x + dir[i][0], new_y = cur_y + dir[i][1];
                // out of bound
                if(new_x < 0 or new_x >= m or new_y < 0 or new_y >= n) continue;
                // obstacle
                if(grid[new_x][new_y] == 2) continue;
                // visited
                if(visited[new_x][new_y]) continue;
                // found
                if(buildings.find(new_x * n + new_y) != buildings.end()){
                    min_dist += dist+1; // add this distance inside min_dist
                    buildings.erase(new_x * n + new_y); // has found it
                }
                if(grid[new_x][new_y] == 1) continue; // cannot pass this building
                visited[new_x][new_y] = true;
                q.push({new_x, new_y, dist+1});
            }
        }
        // if we don't find all buildings
        if(!buildings.empty()) return INT_MAX;
        return min_dist;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        // Initial thought:
        // brute force solution: O(mn) * O(# of buildings) ~= O(mn) * O(mn)
        // O(mn)
        m = grid.size(), n = grid[0].size();
        unordered_set<int> buildings;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    buildings.insert(i*n+j);
                }
            }
        }
        int min_dist = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    // perform bfs until all nodes are found
                    min_dist = min(min_dist,
                                   bfs(grid, i, j, buildings, min_dist));
                }
            }
        }
        if(min_dist == INT_MAX) return -1;
        return min_dist;
    }
};
