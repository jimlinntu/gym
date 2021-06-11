class Solution {
public:
    int find_leader(vector<int> &parent, int i){
        if(parent[i] == i) return i;
        parent[i] = find_leader(parent, parent[i]);
        return parent[i];
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(auto &edge: edges){
            int l1 = find_leader(parent, edge[0]);
            int l2 = find_leader(parent, edge[1]);
            // They are already in the same connected component
            if(l1 == l2) return false;
            parent[l1] = l2;
        }
        // Check if all nodes fall into the same connected component
        for(int i = 0; i < n-1; i++){
            if(find_leader(parent, i) != find_leader(parent, i+1)) return false;
        }
        return true;
    }
};
