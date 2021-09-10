struct E{
    int node;
    int cost;
    bool operator>(const E &r) const{
        return cost > r.cost;
    }
};
class Solution {
public:
	// O(ElogE)
    int minimumCost(int n, vector<vector<int>>& c) {
        vector<vector<E>> g(n);
        for(int i = 0; i < c.size(); i++){
            int x = c[i][0]-1, y = c[i][1]-1, cost = c[i][2];
            g[x].push_back({y, cost});
            g[y].push_back({x, cost});
        }
        unordered_set<int> visited;
        priority_queue<E, vector<E>, greater<E>> pq;
        int ans = 0;
        // node 0 with cost 0
        pq.push({0, 0});
        while(!pq.empty() and visited.size() < n){
            E e = pq.top();
            pq.pop();
            // already added
            if(visited.count(e.node)) continue;
            visited.insert(e.node);
            // Add this node to the tree
            ans += e.cost;
            // Add all its neighbors into the tree
            for(int i = 0; i < g[e.node].size(); i++){
                pq.push(g[e.node][i]);
            }
        }
        if(visited.size() < n) return -1;

        return ans;
    }
};
