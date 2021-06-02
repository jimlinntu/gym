class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_sum = 0;
        // Intuition: try every starting point
        int i, j;
        for(i = 0; i < n; i = j+1){
            int cur_sum = 0;
            for(j = i; j < n; j++){
                int d = gas[j] - cost[j];
                total_sum += d; // accumulate to total_sum
                cur_sum += d;
                if(cur_sum < 0) break;
            }
            // Otherwise, because d[i] + d[i+1] .. d[i+j] < 0
            // and d[i] + d[i+1] + ... d[k] >= 0 for every k in [i, i+j-1]
            // Thus
            //   (d[i] + d[i+1] ... d[k-1]) + (d[k] + d[k+1] ... d[i+j]) < 0
            // => d[k] + d[k+1] ... d[i+j] < 0
            // because (d[i] + d[i+1] ... d[k-1]) >= 0
            if(cur_sum >= 0) break;
            
        }
        if(total_sum < 0) return -1;
        return i;
    }
};
