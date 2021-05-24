using Edge = vector<int>;
using Graph = vector<Edge>;
class Solution {
public:
    int n;
    stack<int> stk;
    vector<bool> visited;
    bool exist_path(Graph &g, Edge &removed_edge){
        int a = removed_edge[0], b = removed_edge[1];
        visited.resize(n+1);
        fill(visited.begin(), visited.end(), false);
        while(!stk.empty()) stk.pop();

        stk.push(a);
        // DFS find whether a, b is connected after `removed_edge` is removed
        while(!stk.empty()){
            int cur = stk.top();
            stk.pop();
            for(int i = 0; i < g[cur].size(); i++){
                int neighbor = g[cur][i];
                // This edge is removed
                if((cur == removed_edge[0] and neighbor == removed_edge[1]) or
                   (cur == removed_edge[1] and neighbor == removed_edge[0]))
                    continue;
                if(visited[neighbor]) continue;
                if(neighbor == b) return true;

                stk.push(neighbor);
                visited[neighbor] = true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        n = edges.size();
        Graph g(n+1);
        for(auto &e: edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        // O(n^2): For each edge,
        //         we check whether they are connected by a path
        for(int i = n-1; i >= 0; i--){
           // if there is a path existing after removing edges[i]
           // we know that this edge is redundant
           if(exist_path(g, edges[i])) return edges[i];
        }
        return {};
    }
};
