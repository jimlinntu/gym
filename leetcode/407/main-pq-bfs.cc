struct Cell{
    int x, y, h;
    bool operator>(const Cell &r) const{
        return h > r.h;
    }
};

class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        // Push the border cells
        bool seen[201][201] = {false};
        for(int i = 0; i < m; i++){
            pq.push({i, 0, heightMap[i][0]});
            pq.push({i, n-1, heightMap[i][n-1], });
            seen[i][0] = seen[i][n-1] = true;
        }
        for(int j = 1; j < n-1; j++){
            pq.push({0, j, heightMap[0][j], });
            pq.push({m-1, j, heightMap[m-1][j],});
            seen[0][j] = seen[m-1][j] = true;
        }

        int ans = 0;
        int cur_border_h = 0; // the initial border height is 0
        // TC: O(mn log (mn)) because the cells inside the PQ forms a border
        // the border contains at most O(mn) cells
        while(!pq.empty()){
            Cell c = pq.top(); // pop the minimum
            pq.pop();
            cur_border_h = max(cur_border_h, c.h);
            // Its neighbor's amount of trapped water is decided
            for(int d = 0; d < 4; d++){
                int nx = c.x + dir[d][0], ny = c.y + dir[d][1];
                if(nx < 0 or nx >= m or ny < 0 or ny >= n) continue;
                if(seen[nx][ny]) continue;
                int nh = heightMap[nx][ny];
                seen[nx][ny] = true;
                
                if(cur_border_h > nh) ans += cur_border_h - nh;
                // push into it to form a new border
                pq.push({nx, ny, nh});
            }
        }

        return ans;
    }
};
