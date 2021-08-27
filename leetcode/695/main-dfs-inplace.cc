struct E{
    int x, y;
};
class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int dfs(vector<vector<int>> &grid, int x, int y){
        stack<E> stk;
        if(grid[x][y] == 1){
            grid[x][y] = 2;
            stk.push({x, y});
        }
        int area = 0;
        while(!stk.empty()){
            E e = stk.top();
            area++;
            stk.pop();
            for(int i = 0; i < 4; i++){
                int nx = e.x + dir[i][0], ny = e.y + dir[i][1];
                if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                if(grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                stk.push({nx, ny});
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
