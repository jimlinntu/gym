class Solution {
public:
    int find_leader(vector<int> &parent, int i){
        if(parent[i] == i) return i;
        // path compression
        int leader = find_leader(parent, parent[i]);
        parent[i] = leader;
        return leader;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 0);
        for(int i = 1; i <= n; i++) parent[i] = i;
        for(auto &edge: edges){
            int a = edge[0], b = edge[1];
            int leader_a = find_leader(parent, a);
            int leader_b = find_leader(parent, b);
            // We detect a cycle
            if(leader_a == leader_b) return edge;
            if(rank[leader_a] >= rank[leader_b]){
                // leader_a has a deeper depth
                // Make leader_b leader_a's child
                parent[leader_b] = leader_a;
                if(rank[leader_a] == rank[leader_b]) rank[leader_a]++;
            }else{
                parent[leader_a] = leader_b;
            }
        }
        return {};
    }
};
