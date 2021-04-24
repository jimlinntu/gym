using t = tuple<int, int, int>;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src == dst) return 0;
        vector<vector<vector<int>>> edges(101);
        for(int i = 0; i < flights.size(); i++){
            edges[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        // global_hops[i] == The hops from src to i
        int global_hops[101];
        fill_n(global_hops, 101, INT_MAX);
        // Minimum priority queue
        priority_queue<t, vector<t>, greater<t>> pq;
        // (distance, how many hops (or edges), cur)
        pq.push({0, 0, src});
        while(!pq.empty()){
            int d, hops, cur;
            // Expand the closest first
            tie(d, hops, cur) = pq.top();
            pq.pop();
            if(cur == dst) return d;
            // do not push the neighbors of a node with hops == K+1
            if(hops == K+1) continue;
            // If it comes later with a larger distance and more hops
            // we will not expand this node.
            // Because there exists a shorter distance with less hops
            // Ex. a -> b: cost 5
            //     a -> c -> b: cost 1000
            // When we visit b with the second path, this is totally useless.
            if(hops >= global_hops[cur]) continue;
            // Tag is as "visited"
            global_hops[cur] = hops;
            // Push its neighbors into the PQ
            for(int i = 0; i < edges[cur].size(); i++){
                int next = edges[cur][i][0];
                int price = edges[cur][i][1];
                pq.push({d + price, hops+1, next});
            }
        }
        return -1;
    }
};
