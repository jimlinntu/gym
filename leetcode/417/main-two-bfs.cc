class Solution {
public:
    int m, n;
    // left, right, up, down
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // 0 for not visited, 1 for pacific, 2 for atlantic
    vector<vector<int>> map;
    vector<vector<int>> ans;

    void bfs(vector<vector<int>> &h){
        queue<pair<int, int>> q;
        q.push({0, 0});
        map[0][0] = 1;
        for(int i = 1; i < n; i++){
            q.push({0, i});
            map[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            q.push({i, 0});
            map[i][0] = 1;
        }
        int x, y;
        while(!q.empty()){
            tie(x, y) = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(xx < 0 or xx >= m) continue;
                if(yy < 0 or yy >= n) continue;
                // Is already occupied
                if(map[xx][yy] != 0) continue;
                // Water can climb up
                if(h[xx][yy] >= h[x][y]){
                    q.push({xx, yy});
                    map[xx][yy] = 1;
                }
            }
        }
    }
    void bfs2(vector<vector<int>> &h){
        queue<pair<int, int>> q;
        q.push({m-1, n-1});
        if(map[m-1][n-1] == 1){
            ans.push_back({m-1, n-1});
        }
        map[m-1][n-1] = 2;
        for(int i = 0; i < n-1; i++){
            q.push({m-1, i});
            if(map[m-1][i] == 1) ans.push_back({m-1, i});
            map[m-1][i] = 2;
        }
        for(int i = 0; i < m-1; i++){
            q.push({i, n-1});
            if(map[i][n-1] == 1) ans.push_back({i, n-1});
            map[i][n-1] = 2;
        }
        int x, y;
        while(!q.empty()){
            tie(x, y) = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int xx = x + dir[i][0];
                int yy = y + dir[i][1];
                if(xx < 0 or xx >= m) continue;
                if(yy < 0 or yy >= n) continue;
                if(map[xx][yy] == 2) continue;
                // Water can only climb up
                if(h[xx][yy] < h[x][y]) continue;
                // Meet a pacific mark, push an (xx, yy)
                if(map[xx][yy] == 1){
                    ans.push_back({xx, yy});
                }
                map[xx][yy] = 2; // occupy it
                q.push({xx, yy});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // Reverse thinking
        // Water is climbing from the ocean to the mountains
        m = heights.size();
        n = heights[0].size();
        map = vector<vector<int>>(m, vector<int>(n, 0));
        bfs(heights);
        bfs2(heights);
        return ans;
    }
};
