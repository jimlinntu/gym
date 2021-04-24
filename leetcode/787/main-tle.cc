class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst) return 0;
        vector<vector<vector<int>>> edges(101);
        for(int i = 0; i < flights.size(); i++){
            // edges[src] = [(dst, price)]
            edges[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, int>> q;
        q.push({src, 0});
        int cheapest_price = numeric_limits<int>::max();
        int cur, dist, next, price;
        // K-steps BFS
        while(!q.empty() and (K--) >= 0){
            // Layer-level BFS
            for(int s = q.size()-1; s >= 0; s--){
                cur = q.front().first;
                dist = q.front().second;
                q.pop();
                for(int i = 0; i < edges[cur].size(); i++){
                    next = edges[cur][i][0];
                    price = edges[cur][i][1];
                    if(next == dst) cheapest_price = min(cheapest_price, dist+price);
                    if(next != dst) q.push({next, dist+price});
                }
            }
        }
        return (cheapest_price == numeric_limits<int>::max())? (-1):(cheapest_price);
    }
};
