class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size();
        n = rooms[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0) q.push({i, j});
            }
        }

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
                    if(rooms[nx][ny] == 0 or rooms[nx][ny] == -1) continue;
                    // this distance is not better
                    if(dist >= rooms[nx][ny]) continue;
                    rooms[nx][ny] = min(rooms[nx][ny], dist);
                    q.push({nx, ny});
                }
            }
        }
    }
};
