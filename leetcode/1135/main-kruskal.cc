class Solution {
public:
    int find_leader(vector<int> &parent, int i){
        if(parent[i] == i) return i;
        return (parent[i] = find_leader(parent, parent[i]));
    }
    int minimumCost(int n, vector<vector<int>>& c) {
        // Kruskal algorithm
        // Sort by edge costs
        sort(c.begin(), c.end(), [](
            const vector<int> &left, const vector<int> &right)-> bool{
            return left[2] < right[2];
        });
        int ans = 0;
        vector<int> parent(n);
        for(int i = 0; i < n; i++) parent[i] = i;
        // Loop over edges, pick this edge if this edge will not cause a cycle
        for(int i = 0; i < c.size(); i++){
            int x = c[i][0]-1, y = c[i][1]-1, cost = c[i][2];
            int l1 = find_leader(parent, x);
            int l2 = find_leader(parent, y);
            if(l1 != l2){
                // connect two groups
                // NOTE: can use ranking technique, but for simplicity
                // skip this time
                parent[l1] = l2;
                ans += cost;
            }
        }
        // Check all nodes should belong to the same leader (group)
        for(int i = 1; i < n; i++){
            int prev_leader = find_leader(parent, i-1);
            int leader = find_leader(parent, i);
            if(prev_leader != leader) return -1;
        }
        return ans;
    }
};
