using t = tuple<int, int>;
class Solution {
public:
    int d_square(vector<int> &p){
        return p[0] * p[0] + p[1] * p[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // O(n log k)
        // max heap
        priority_queue<t> pq;
        int n = points.size();
        for(int i = 0; i < k; i++){
            auto &p = points[i];
            pq.push({d_square(p), i});
        }
        for(int i = k; i < n; i++){
            auto &p = points[i];
            int d = d_square(p);
            auto [d_furtherest, _] = pq.top();
            if(d < d_furtherest){
                pq.pop();
                pq.push({d, i});
            }
        }
        // Pop them out O(k log k)
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            auto [_, j] = pq.top();
            pq.pop();
            ans.push_back(points[j]);
        }
        return ans;
    }
};
