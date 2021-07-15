class Solution {
public:

    bool hasloop(int cur, vector<vector<int>> &adj,
                 vector<bool> &visited,
                 vector<bool> &path){
        // this is a loop
        if(path[cur]) return true;
        // this substree has been traversed
        if(visited[cur]) return false;
        
        path[cur] = true;
        visited[cur] = true;
        auto &neighbors = adj[cur];
        for(int nei: neighbors){
            if(hasloop(nei, adj, visited, path)) return true;
        }
        path[cur] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& p) {
        vector<bool> visited(n, false), path(n, false);
        vector<vector<int>> adj(n);
        for(vector<int> &edge: p){
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
        }
        
        for(int i = 0; i < n; i++){
            if(hasloop(i, adj, visited, path)) return false;
        }
        return true;
    }
};
