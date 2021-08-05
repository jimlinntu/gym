struct E{
    int x;
    int y_minus_x;
    bool operator<(const E &r) const{
        return y_minus_x < r.y_minus_x;
    }
};
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        // (x, y-x)
        priority_queue<E, vector<E>> pq;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            int x = points[i][0], y = points[i][1];
            while(!pq.empty() and pq.top().x < x-k){
                pq.pop();
            }
            
            if(!pq.empty()){
                ans = max(ans, y + x + pq.top().y_minus_x);
            }

            pq.push({x, y-x});
        }
        return ans;
    }
};
