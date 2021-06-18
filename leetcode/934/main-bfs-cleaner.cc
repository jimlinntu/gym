class Solution {
public:
    int m, n;
    const int MARK = 2;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool invalid(int x, int y){
        return x < 0 or x >= m or y < 0 or y >= n;
    }

    pair<int, int> first_one(vector<vector<int>> &g){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j]) return {i, j};
            }
        }
        assert(false);
        return {-1, -1};
    }

    void mark_and_collect(vector<vector<int>> &g,
                          vector<vector<int>> &p,
                          queue<vector<int>> &next_q){
        int x, y;
        tie(x, y) = first_one(g);
        queue<vector<int>> q;
        g[x][y] = MARK;
        q.push({x, y});
        next_q.push({x, y});

        while(!q.empty()){
            x = q.front()[0], y = q.front()[1];
            q.pop();
            for(int d = 0; d < 4; d++){
                int xx = x + dir[d][0];
                int yy = y + dir[d][1];
                if(invalid(xx, yy)) continue;
                if(g[xx][yy] == 0) continue;
                if(g[xx][yy] == MARK) continue;
                g[xx][yy] = MARK;
                q.push({xx, yy});
                next_q.push({xx, yy});
            }
        }
    }

    int find_bridge(vector<vector<int>> &g,
                    vector<vector<int>> &p,
                    queue<vector<int>> &q){
        int dist = 0;
        while(!q.empty()){
            for(int i = q.size()-1; i >= 0; i--){
                int x = q.front()[0], y = q.front()[1];
                q.pop();
                for(int d = 0; d < 4; d++){
                    int xx = x + dir[d][0];
                    int yy = y + dir[d][1];
                    if(invalid(xx, yy)) continue;
                    // we encounter ourself, continue
                    if(g[xx][yy] == MARK) continue;
                    // we encounter the other island, return
                    if(g[xx][yy] == 1) return dist;
                    g[xx][yy] = MARK; // expand this island
                    q.push({xx, yy});
                }
            }
            dist++;
        }
        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> p;
        queue<vector<int>> q;
        mark_and_collect(grid, p, q);
        return find_bridge(grid, p, q);
    }
};
