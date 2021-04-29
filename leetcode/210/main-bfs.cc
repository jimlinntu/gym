using Graph = vector<vector<int>>;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        Graph g(n);
        for(auto &pre: prerequisites){
            g[pre[1]].push_back(pre[0]);
        }
        vector<int> indeg(n, 0);
        for(int i = 0; i < n; i++){
            for(int neighbor: g[i]){
                indeg[neighbor]++;
            }
        }
        vector<int> topology;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indeg[i] == 0) q.push(i);
        }
        // O(V+E)
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            topology.push_back(cur);
            assert(indeg[cur]-- == 0);
            // this node is removed
            for(int neighbor: g[cur]){
                if(--indeg[neighbor] == 0) q.push(neighbor);
            }
        }

        if(topology.size() != n) return {};
        return topology;
    }
};
