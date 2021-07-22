class Solution {
public:
    bool traverse(int cur, vector<vector<int>> &g,
                  vector<bool> &s1, vector<bool> &s2){
        // We need to put cur into s1 but it already exists in s2
        // ==> impossible to partition this graph biparitely
        if(s2[cur]) return false;
        if(s1[cur]) return true; // already checked
        s1[cur] = true; // mark it in this set

        // If (cur, nei) edge appears, we know cur and nei must be placed in different sets
        for(int nei: g[cur]){
            // NOTE: swap s1 s2 here
            if(!traverse(nei, g, s2, s1)) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        // there is no edge: return true
        if(n < 2) return true;
        vector<bool> s1(n, false), s2(n, false);
        for(int i = 0; i < n; i++){
            assert(s1[i] == false or s2[i] == false);
            // If this node i already belongs to s1 or s2,
            // we can know this subgraph has been visited
            if(s1[i] or s2[i]) continue; 
            if(!traverse(i, graph, s1, s2)) return false;
        }
        return true;
    }
};
