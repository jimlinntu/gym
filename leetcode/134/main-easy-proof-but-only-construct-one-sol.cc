class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // Assume total_sum >= 0:
        // Find an i s.t.
        // d[0] + d[1] + ... d[i] (i >= 0)
        // is the mininum prefix sum
        // Consider starting from i+1
        // Because (d[0] + d[1] + .. + d[i]) <= (d[0] + d[1] + .. + d[i]) + .. + d[j]
        // => d[i+1] + ... d[j] >= 0
        // for every i < j <= n-1
        // Consider (d[i+1] + d[i+2] ... d[n-1]) + (d[0] + d[1] .. + d[k])
        //       >= (d[i+1] + d[i+2] ... d[n-1]) + (d[0] + d[1] .. + d[k] + .. d[i])
        //       (because (d[0] + d[1] .. + d[k] + .. d[i]) is the smallest prefix sum)
        //       == total_sum >= 0
        // for every 0 <= k <= i
        // Thus, i+1 --> n-1 --> k can be traveled successfully!
        // Thus (total_sum >= 0) <===> (we can find a starting point)

        //
        // Consider i == n-1: (starting point 0)
        // Proof: d[0] + d[1] + d[2] .. + d[n-1] will not necessary be the smallest prefix
        // d = [0, 1, 2, 3, 4]
        // As you can see, sum(d) == 10
        // But 0 can be the starting point!
        
        // I think the reason why this algorithm will work is because:
        // if a starting point exists, there is only one (gauranteed by the description)
        // Because this algorithm can construct one, this must be the answer!!

        int total_sum = 0;
        int min_prefix_sum = INT_MAX;
        int start;
        for(int i = 0; i < n; i++){
            int d = gas[i] - cost[i];
            total_sum += d;
            // [0, i] prefix sum
            if(total_sum < min_prefix_sum){
                start = i;
                min_prefix_sum = total_sum;
            }
        }
        if(total_sum >= 0) return (start+1)%n;
        return -1;
    }
};
