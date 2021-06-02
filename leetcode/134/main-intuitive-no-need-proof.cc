class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // Intuition: try every starting point
        for(int i = 0, j; i < n; i += j+1){
            int cur_sum = 0;
            // Simulate traveling
            for(j = 0; j < n; j++){
                int k = (i+j)%n;
                int d = gas[k] - cost[k];
                if(cur_sum + d >= 0) cur_sum += d;
                else break;
            }
            // If we successfully have a round trip, return
            if(j == n) return i;
            // Otherwise, keep going
        }
        return -1;
    }
};
