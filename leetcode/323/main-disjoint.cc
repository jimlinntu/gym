class Solution {
public:
    int find_leader(vector<int> &parent, int i){
        if(parent[i] == i) return i;
        parent[i] = find_leader(parent, parent[i]);
        return parent[i];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int num_ccs = n;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(auto &e: edges){
            int a = e[0], b = e[1];
            int la = find_leader(parent, a);
            int lb = find_leader(parent, b);
            if(la == lb) continue;
            // Every time we merge a group, we lose a cc
            num_ccs--;
            if(rank[la] >= rank[lb]){
                // The depth of la is larger
                parent[lb] = la;
                if(rank[la] == rank[lb]) rank[la]++;
            }else{
                parent[la] = lb;
            }
        }
        return num_ccs;
    }
};
