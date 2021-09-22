class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size();
        int n = N / 2;
        vector<int> indices;
        for(int i = 0; i < N; i++) indices.push_back(i);
        // Intuition:
        // a1 + a2 + a3 + a4
        // choose 2 a and change them to b
        // which will you choose?
        // choose a that d = b-a is the smallest!
        sort(indices.begin(), indices.end(), [&costs](int l, int r) -> bool{
            return costs[l][1]-costs[l][0] < costs[r][1]-costs[r][0];
        });
        
        int ans = 0;
        // choose b
        for(int i = 0; i < n; i++){
            ans += costs[indices[i]][1];
        }
        // choose a
        for(int i = n; i < N; i++){
            ans += costs[indices[i]][0];
        }
        return ans;
    }
};
