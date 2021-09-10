struct P{
    int x, y;
};
class Solution {
public:
    int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<P> q;
        int ans = 0;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if(grid[0][0] == 0){
            visited[0][0] = true;
            q.push({0, 0});
        }
        bool reach = false;
        while(!q.empty() and !reach){
            // Level BFS
            ans++;
            for(int i = q.size()-1; i >= 0; i--){
                P p = q.front();
                q.pop();
                if(p.x == n-1 and p.y == n-1) reach = true;
                // Expand neighbors
                for(int d = 0; d < 8; d++){
                    int nx = p.x+dir[d][0], ny = p.y+dir[d][1];
                    if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                    if(visited[nx][ny]) continue;
                    if(grid[nx][ny] == 1) continue;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        if(!reach) return -1;
        return ans;
    }
};
