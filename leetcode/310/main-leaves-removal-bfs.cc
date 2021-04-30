using Graph = vector<unordered_set<int>>;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> deg(n, 0);
        if(n == 1) return {0};
        Graph g(n);
        for(auto &edge: edges){
            g[edge[0]].insert(edge[1]);
            g[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        // Initially, the queue only contains leaves
        for(int i = 0; i < n; i++){
            if(g[i].size() == 1) q.push(i);
        }

        while(n > 2){
            // Remove how many nodes here
            n -= q.size();
            for(int i = q.size()-1; i >= 0; i--){
                int cur = q.front();
                q.pop();
                for(int neighbor: g[cur]){
                    // remove the neighbor -> cur link
                    g[neighbor].erase(cur);
                    if(g[neighbor].size() == 1) q.push(neighbor);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
