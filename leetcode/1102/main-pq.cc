struct Node{
    int r, c;
    int score;
    bool operator<(const Node &r) const{
        return score < r.score;
    }
};
class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Always expand using the largest node!
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<Node> pq;
        pq.push({0, 0, grid[0][0]});
        visited[0][0] = true;
        while(!pq.empty()){
            // Expand using the largest score's path!
            Node cur = pq.top();
            if(cur.r == m-1 and cur.c == n-1) return cur.score;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int x = cur.r + dir[i][0], y = cur.c + dir[i][1];
                if(x < 0 or x >= m or y < 0 or y >= n) continue;
                if(visited[x][y]) continue;
                visited[x][y] = true;
                Node neighbor = {x, y, min(cur.score, grid[x][y])};
                pq.push(neighbor);
            }
        };
        return -1;
    }
};
