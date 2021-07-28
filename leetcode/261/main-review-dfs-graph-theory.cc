
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // According to Intro to Algo Tree's property 4,
        // a tree == G is connected and |E| = |V|-1
        if(edges.size() != n-1) return false;
        vector<vector<int>> g(n);
        for(auto &e: edges){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int num_nodes = 1;
        // check how many nodes are conneceted
        vector<bool> visited(n, false);
        stack<int> stk;
        stk.push(0);
        visited[0] = true;
        while(!stk.empty()){
            int cur = stk.top();
            stk.pop();
            for(int nei: g[cur]){
                if(visited[nei]) continue; // visited before
                visited[nei] = true;
                stk.push(nei);
                num_nodes++; // a node is visited
            }
        }
        return num_nodes == n;
    }
};
