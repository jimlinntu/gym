class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], i, 0});
        }
        // O(n log n) + O(k log n)
        int val, row, col;
        while(--k > 0){
            tie(val, row, col) = pq.top();
            pq.pop();
            // expand the next one
            if(col+1 < n){
                pq.push({matrix[row][col+1], row, col+1});
            }
        }
        return get<0>(pq.top());
    }
};
