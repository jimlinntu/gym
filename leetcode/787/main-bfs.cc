class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst) return 0;
        vector<vector<vector<int>>> edges(101);
        for(int i = 0; i < flights.size(); i++){
            edges[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        // dist[i] == The distance from src to i
        int dist[101];
        fill_n(dist, 101, INT_MAX);
        queue<pair<int, int>> q;
        int ans = INT_MAX;
        q.push({src, 0});
        while(!q.empty() and (K--) >= 0){
            for(int i = q.size()-1; i >= 0; i--){
                int cur = q.front().first;
                int d = q.front().second;
                q.pop();
                for(int j = 0; j < edges[cur].size(); j++){
                    int next = edges[cur][j][0];
                    int price = edges[cur][j][1];
                    // If dist[next] != INT_MAX,
                    // we know that this node has been visited at least one time
                    // If we want to consider this node again,
                    // d + price < dist[next] must hold
                    // This can avoid a BFS loop
                    if(d + price < dist[next]){
                        dist[next] = d + price;
                        if(next != dst) q.push({next, d + price});
                        else ans = min(ans, d + price);
                    }
                }
            }
        }
        return (ans == INT_MAX)? (-1):(ans);
    }
};
