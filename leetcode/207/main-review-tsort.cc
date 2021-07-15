class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& p) {
        vector<bool> visited(n, false), path(n, false);
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        unordered_set<int> remain;
        for(vector<int> &edge: p){
            int a = edge[0], b = edge[1];
            // a -> b if we have to finish b first
            adj[a].push_back(b);

            // the node we want to delete
            if(indeg[b]++ == 0) remain.insert(b);
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            // delete this node
            for(int nei: adj[cur]){
                // if the next node's indeg == 0, then we add it to the queue
                if(--indeg[nei] == 0){
                    remain.erase(nei);
                    q.push(nei);
                }
            }
        }

        // == 0 means we do not have a cycle => can finish
        return remain.size() == 0;
    }
};
