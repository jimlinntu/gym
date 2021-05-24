class Solution {
public:
    int find_leader(vector<int> &parent, int i){
        if(parent[i] == i) return i;
        parent[i] = find_leader(parent, parent[i]);
        return parent[i];
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++) parent[i] = i;
        vector<int> indeg(n+1, 0);

        int critical_node = -1;
        for(auto &edge: edges){
            if(++indeg[edge[1]] == 2) critical_node = edge[1];
        }
        // Case 1, 2(ii)
        if(critical_node != -1){
            vector<int> candidate1;
            vector<int> candidate2;
            // Collect candidate1 and candidate2
            for(auto &edge: edges){
                if(edge[1] == critical_node){
                    if(candidate1.empty()) candidate1 = edge;
                    else candidate2 = edge;
                }
            }
            assert(!candidate1.empty() and !candidate2.empty());
            // Try delete candidate2
            // (because the problem requires us to choose the last one)
            // And do a union find (undirected)
            for(auto &edge:edges){
                if(edge == candidate2) continue;
                int u = edge[0], v = edge[1];
                int leader_u = find_leader(parent, u);
                int leader_v = find_leader(parent, v);
                // Remove candidate1 will still cause a loop
                // So it must be candidate2
                if(leader_u == leader_v) return candidate1;
                parent[leader_u] = leader_v;
            }
            // Deleting candidate2 works quite well
            // So it must be candidate1
            return candidate2;
        }else{
            // Case 2(i)
            // Do a union find
            // The first one causes a loop will be the answer
            for(auto &edge:edges){
                int u = edge[0], v = edge[1];
                int leader_u = find_leader(parent, u);
                int leader_v = find_leader(parent, v);
                // This candidate
                if(leader_u == leader_v) return edge;
                parent[leader_u] = leader_v;
            }
        }
        return {};
    }
};
