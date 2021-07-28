struct E{
    int parent;
    int cur;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto &e: edges){
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int num_nodes = 0;
        vector<bool> visited(n, false);
        stack<E> stk;
        // start from a random node
        stk.push({-1, 0});
        visited[0] = true;
        num_nodes++;
        while(!stk.empty()){
            E c = stk.top();
            stk.pop();
            // loop over neighbors
            for(int nei: g[c.cur]){
                if(nei == c.parent) continue; // do not go back to its neighbor
                if(visited[nei]) return false; // found a cycle
                visited[nei] = true;
                num_nodes++;
                stk.push({c.cur, nei});
            }
        }
        return num_nodes == n;
    }
};
