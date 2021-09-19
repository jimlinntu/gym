struct Node{
    int v, w;
};
struct E{
    int v, d;
    bool operator>(const E &r) const{
        return d > r.d;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<Node>> g(n);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0]-1, v = times[i][1]-1, w = times[i][2];
            g[u].push_back({v, w});
        }
        int start = k-1;
        int cnt = 0;
        int ans = 0;
        priority_queue<E, vector<E>, greater<E>> pq;
        vector<int> dist(n, INT_MAX);
        pq.push({start, 0});
        while(!pq.empty()){
            E cur = pq.top();
            pq.pop();
            if(cur.d >= dist[cur.v]) continue;
            dist[cur.v] = cur.d;
            ans = max(ans, cur.d);
            cnt++;
            
            // Expand neighbors
            for(Node neighbor: g[cur.v]){
                // already visited
                if(dist[neighbor.v] != INT_MAX) continue;
                pq.push({neighbor.v, cur.d+neighbor.w});
            }
        }
        
        return (cnt < n)?(-1):(ans);
    }
};
