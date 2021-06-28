using V = vector<int>;
using VV = vector<vector<int>>;

class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool bfs(VV &grid, int x, int y,
             VV &distmap, VV &count_reach, int bidx){
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        visited[x][y] = true;
        q.push({x, y});
        int max_count = 0;
        int dist = 0;
        while(!q.empty()){
            dist++; // pre-add it
            for(int i = q.size()-1; i >= 0; i--){
                int cx, cy;
                tie(cx, cy) = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nx = cx + dir[j][0], ny = cy + dir[j][1];
                    // out of bound
                    if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                    // obstacle or building
                    if(grid[nx][ny] > 0) continue;
                    // visited
                    if(visited[nx][ny]) continue;

                    visited[nx][ny] = true;
                    if(distmap[nx][ny] == INT_MAX) distmap[nx][ny] = 0;
                    distmap[nx][ny] += dist; // add the shortest distance into this grid
                    count_reach[nx][ny]++;
                    // record
                    max_count = max(count_reach[nx][ny], max_count);
                    q.push({nx, ny});
                }
            }
        }
        // Say if this building idx is 2 (3 buildings) and we only have 2 as our max count
        // => no need to find anymore
        if(max_count < bidx+1)
            return false; // no way to find an empty land that is reachable from all buildings
        return true;
    }

    int shortestDistance(vector<vector<int>>& grid) {
        // Initial thought:
        // brute force solution: O(mn) * O(# of buildings) ~= O(mn) * O(mn)
        // Let B = # of buildings, E = # of empty lands
        // O(B * mn) must be better than O(E * mn) for most of the cases
        m = grid.size(), n = grid[0].size();
        V buildings;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) buildings.push_back(i*n+j);
            }
        }
        // starting from each building
        VV count_reach(m, V(n, 0));
        VV distmap(m, V(n, INT_MAX));
        for(int i = 0; i < buildings.size(); i++){
            int xy = buildings[i];
            int x = xy / n, y = xy % n;
            if(!bfs(grid, x, y, distmap, count_reach, i)) return -1;
        }
        // Get the distance from the distmap
        int min_dist = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(count_reach[i][j] == buildings.size())
                    min_dist = min(min_dist, distmap[i][j]);
            }
        }
        if(min_dist == INT_MAX) return -1;
        return min_dist;
    }
};
