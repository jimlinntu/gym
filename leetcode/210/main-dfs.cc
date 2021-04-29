using Graph = vector<vector<int>>;
using Mask = vector<int>;
class Solution {
public:
    bool check_cycle(int cur, Graph &g, Mask &visited, Mask &path,
                     vector<int> &topology){
        if(path[cur]) return true; // there is a cycle
        if(visited[cur]) return false;
        visited[cur] = true;
        path[cur] = true;
        for(int neighbor: g[cur]){
            if(check_cycle(neighbor, g, visited, path, topology)) return true;
        }
        path[cur] = false; // pop it
        topology.push_back(cur); // we should push_back the subtree under cur first
        return false; // no cycle
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        Graph g(n);
        for(auto &pre: prerequisites){
            g[pre[1]].push_back(pre[0]);
        }
        Mask visited(n, false), path(n, false);
        vector<int> topology;
        for(int i = 0; i < n; i++){
            if(check_cycle(i, g, visited, path, topology)) return {};
        }
        reverse(topology.begin(), topology.end());
        return topology;
    }
};
