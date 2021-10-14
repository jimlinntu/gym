struct Node{
    int city;
    int cost;
};
struct E{
    int city;
    int dist;
    int hop;
    bool operator>(const E &r) const{
        return dist > r.dist;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<Node>> g(n);
        for(int i = 0; i < flights.size(); i++){
            auto &f = flights[i];
            int s = f[0], d = f[1], cost = f[2];
            g[s].push_back({d, cost});
        }
        k++;
        // min pq
        vector<int> dist(n, INT_MAX);
        priority_queue<E, vector<E>, greater<E>> pq;
        pq.push({src, 0, 0});
        while(!pq.empty()){
            E cur = pq.top();
            pq.pop();

            if(cur.city == dst) return cur.dist;
            // worse, do not have to reexpand
            if(cur.dist < dist[cur.city])
                dist[cur.city] = cur.dist;
            if(cur.hop == k) continue; // cannot expand
            // Expand
            for(Node &neighbor: g[cur.city]){
                if(cur.dist + neighbor.cost < dist[neighbor.city])
                    pq.push({neighbor.city, cur.dist+neighbor.cost, cur.hop+1});
            }
        }
        return -1;
    }
};
