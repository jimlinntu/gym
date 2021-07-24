class Solution {
public:
    int dir[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // Peform a tsort
        int outdeg[200][200] = {0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // if u->v, them outdeg[u]++
                for(int d = 0; d < 4; d++){
                    int x = i + dir[d][0], y = j + dir[d][1];
                    if(x < 0 or x >= m or y < 0 or y >= n) continue;
                    if(matrix[i][j] < matrix[x][y]){
                        outdeg[i][j]++;
                    }
                }
            }
        }
        int ans = 1; // at least each node can form a path of length 1
        queue<pair<int, int>> q;
        int depth[200][200] = {0};
        // Initially, nodes without children depth is 1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(outdeg[i][j] == 0){
                    q.push({i, j});
                    depth[i][j] = 1;
                }
            }
        }
        // DP step
        int x, y;
        while(!q.empty()){
            tie(x, y) = q.front();
            q.pop();
            ans = max(ans, depth[x][y]);
            // update its parent
            for(int d = 0; d < 4; d++){
                int nx = x + dir[d][0], ny = y + dir[d][1];
                if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                if(matrix[x][y] > matrix[nx][ny]){
                    depth[nx][ny] = max(depth[nx][ny], 1+depth[x][y]);
                    
                    // Add this into the queue when this out degree reaches zero
                    if(--outdeg[nx][ny] == 0) q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};
