class Solution {
public:
    bool is_tree = true;
    int count = 0;
    void dfs(int par, int cur, vector<bool> &visited,
            vector<vector<int>> &g){
        if(!is_tree) return; // no need to traverse anymore
        // If it is a tree, its children should not be able to see a visited node!
        if(visited[cur]){
            is_tree = false;
            return;
        }
        visited[cur] = true;
        count++;
        // loop over neighbors (children)
        for(int nei: g[cur]){
            if(nei != par)
                dfs(cur, nei, visited, g);
        }
        return;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto &e: edges){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }

        // start from a random node
        // if it is a valid tree, all nodes will be connected and all nodes can
        // act as a root
        vector<bool> visited(n, false);
        dfs(-1, 0, visited, g);
        // 
        if(!is_tree) return false;
        // some nodes are not connected to this tree
        if(count != n) return false;
        return true;
    }
};
