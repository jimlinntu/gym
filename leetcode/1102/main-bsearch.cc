class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
    bool check_reachable(int x, int y, int lb,
                         vector<vector<bool>> &visited,
                         vector<vector<int>> &grid){
        if(x < 0 or x >= m or y < 0 or y >= n) return false;
        if(visited[x][y]) return false;
        if(grid[x][y] < lb) return false;
        visited[x][y] = true;
        if(x == m-1 and y == n-1) return true;
        for(int i = 0; i < 4; i++){
            int r = x + dir[i][0], c = y + dir[i][1];
            if(check_reachable(r, c, lb, visited, grid))
                return true;
        }
        return false;
    }
    int maximumMinimumPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int bound = min(grid[0][0], grid[m-1][n-1]);
        vector<int> vals;

        for(int i = 0; i < m*n; i++){
            int v = grid[i/n][i%n];
            // The maximum minimum value <= bound!!!!
            if(v <= bound) vals.push_back(v);
        }
        // [T, T, T, F, F, F ...]
        sort(vals.begin(), vals.end());
        int l = 0, r = vals.size();
        // O(mn log mn)
        while(l < r){
            int mid = (l+r)/2;
            int v = vals[mid];
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            bool can = check_reachable(0, 0, v, visited, grid);
            if(can){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        // l is the first value that is unable to
        // let us get to (m-1, n-1)
        return vals[l-1];
    }
};
