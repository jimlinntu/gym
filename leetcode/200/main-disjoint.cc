class Solution {
public:
    int m, n;
    int find_leader(vector<int> &parent, int i){
        if(parent[i] == i) return i;
        parent[i] = find_leader(parent, parent[i]);
        return parent[i];
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int mn = m*n;
        
        vector<int> parent(mn);
        vector<int> rank(mn, 0);
        // up, left, right, down
        int d[4] = {-n, -1, +1, n};

        for(int i = 0; i < mn; i++) parent[i] = i;
        for(int i = 0; i < mn; i++){
            if(grid[i/n][i%n] == '0') continue;
            for(int j = 0; j < 4; j++){
                int neighbor = i + d[j];
                if(j == 1 and (i%n) == 0) continue;
                if(j == 2 and (i%n) == n-1) continue;

                if(neighbor < 0 or neighbor >= mn) continue;
                if(grid[neighbor/n][neighbor%n] == '0') continue;
                // Union neighbor with i
                int leader_i = find_leader(parent, i);
                int leader_neighbor = find_leader(parent, neighbor);
                // they are already in the same union set
                if(leader_i == leader_neighbor) continue;
                if(rank[leader_i] >= rank[leader_neighbor]){
                    parent[leader_neighbor] = leader_i;
                    if(rank[leader_i] == rank[leader_neighbor]) rank[leader_i]++;
                }else parent[leader_i] = leader_neighbor;
            }
        }
        unordered_set<int> island;
        for(int i = 0; i < mn; i++){
            if(grid[i/n][i%n] == '0') continue;
            island.insert(find_leader(parent, i));
        }
        return island.size();
    }
};
