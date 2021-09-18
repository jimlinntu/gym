struct E{
    int x, y, d;
};
class Solution {
public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> out(m, vector<int>(n, -1));
        queue<E> q;
        // Add all 0 to the queue and perform a BFS over all points
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    out[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        while(!q.empty()){
            E cur = q.front();
            q.pop();
            // expand neighbors
            for(int d = 0; d < 4; d++){
                int nx = cur.x + dir[d][0], ny = cur.y + dir[d][1];
                if(nx < 0 or nx == m or ny < 0 or ny == n) continue;
                if(out[nx][ny] != -1) continue; // visited
                out[nx][ny] = cur.d+1; // shortest distance
                q.push({nx, ny, cur.d+1});
            }
        }
        
        return out;
    }
};
