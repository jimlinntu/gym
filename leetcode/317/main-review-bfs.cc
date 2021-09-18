struct E{
    int x, y, d;
};

struct R{
    int cnt_buildings;
    int sum_d;
    R(){
        cnt_buildings = 0;
        sum_d = 0;
    }
};
class Solution {
public:
    int m, n;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool visited[50][50];
    void clear_visited(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = false;
            }
        }
    }
    // O(mn)
    void bfs(int x, int y,
             vector<vector<int>> &grid, vector<vector<R>> &out){
        // start from (x,y) and update out
        clear_visited();
        queue<E> q;
        q.push({x, y, 0});
        visited[x][y] = true;
        while(!q.empty()){
            E cur = q.front();
            q.pop();
            for(int d = 0; d < 4; d++){
                int nx = cur.x + dir[d][0], ny = cur.y + dir[d][1];
                if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                if(visited[nx][ny]) continue;
                if(grid[nx][ny] != 0) continue;
                visited[nx][ny] = true;
                // a building has visited this empty land
                out[nx][ny].cnt_buildings++;
                out[nx][ny].sum_d += cur.d+1;
                q.push({nx, ny, cur.d+1});
            }
        }
        return;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<R>> out(m, vector<R>(n));
        // BFS from all buildings
        int num_buildings = 0;
        // O(Bmn)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    bfs(i, j, grid, out);
                    num_buildings++;
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(out[i][j].cnt_buildings ==num_buildings){
                    if(out[i][j].sum_d < ans){
                        ans = out[i][j].sum_d;
                    }
                }
            }
        }
        return (ans == INT_MAX)?(-1):(ans);
    }
};
