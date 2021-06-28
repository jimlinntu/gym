class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<int>> &r, int x, int y){
        queue<pair<int, int>> q;
        q.push({x, y});
        int dist = 0;
        int cx, cy, nx, ny;
        while(!q.empty()){
            dist++;
            for(int i = q.size()-1; i >= 0; i--){
                tie(cx, cy) = q.front();
                q.pop();
                for(int j = 0; j < 4; j++){
                    nx = cx + dir[j][0], ny = cy + dir[j][1];
                    if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                    if(r[nx][ny] == -1) continue; // do not walk onto an obstacle
                    if(r[nx][ny] == 0) continue; // do not walk onto a gate
                    // if when we step on it, there is already a better value
                    // we will skip it
                    if(dist >= r[nx][ny]) continue;
                    r[nx][ny] = min(r[nx][ny], dist);
                    q.push({nx, ny});
                }
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        vector<pair<int, int>> g;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0) g.push_back({i, j});
            }
        }
        int x, y;
        // expand from each gate to update the shortest distance for each empty room
        for(auto &p: g){
            tie(x, y) = p;
            bfs(rooms, x, y);
        }
    }
};
