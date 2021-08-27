struct E{
    int x, y;
};
class Solution {
public:
    int m, n;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int solve(vector<vector<bool>> &visited,
              vector<vector<int>> &grid,
              int x, int y){
        stack<E> stk;
        if(!visited[x][y] and grid[x][y] == 1){
            visited[x][y] = true;
            stk.push({x, y});
        }
        int area = 0;
        while(!stk.empty()){
            E e = stk.top();
            area++;
            stk.pop();
            // Expand neighbors
            for(int i = 0; i < 4; i++){
                int nx = e.x + dir[i][0], ny = e.y + dir[i][1];
                if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                if(visited[nx][ny]) continue;
                if(grid[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                stk.push({nx, ny});
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int ans = 0;    
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++)
                ans = max(ans, solve(visited, grid, i, j));
        }
        return ans;
    }
};
