class Solution {
public:
    // Ther is a loop starting from `cur`
    bool check_cycle_by_dfs(int cur, vector<vector<int>> &adj,
                            vector<bool> &visit, vector<bool> &path){
        if(path[cur]) return true; // there is a cycle
        if(visit[cur]) return false; // this node's subtree has been visited
        visit[cur] = true;
        path[cur] = true;
        for(int neighbor: adj[cur]){
            if(check_cycle_by_dfs(neighbor, adj, visit, path)) return true;
        }
        path[cur] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto &prereq: prerequisites){
            int a = prereq[0], b = prereq[1];
            adj[b].push_back(a); // you must finish b first
        }
        // Detect cycle
        vector<bool> visit(numCourses, false);
        vector<bool> path(numCourses, false);
        // Complexity: O(V + E) because each node will be at most visited once
        for(int i = 0; i < numCourses; i++){
            if(check_cycle_by_dfs(i, adj, visit, path)) return false;
        }
        return true;
    }
};
