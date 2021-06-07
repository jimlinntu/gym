class Solution {
public:
    bool feasible(vector<int> &weights, int capacity, int days){
        // Simulate putting weights into the ship
        days--; // use one ship
        int cur_capacity = 0;
        for(int w: weights){
            // There is still space for this ship
            if(cur_capacity + w <= capacity){
                cur_capacity += w;
            }else if(days > 0){
                days--;
                cur_capacity = w; // a new ship
            }else return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        assert(days > 0);
        // Binary search over value space
        // O(log (ub - lb))
        // Find the leftmost feasible capacity
        // the lower bound and the upper bound
        int lb = *max_element(weights.begin(), weights.end());
        int ub = 0;
        for(int w: weights) ub += w;
        assert(lb <= ub);
        while(lb < ub){
            int mid = (lb + ub) / 2;
            bool ret = feasible(weights, mid, days);
            if(ret){
                // [lb, mid)
                // [0, 0, 0, 1, 1, 1, 1]
                //           ^ mid
                // If this mid is already the leftmost 1
                // lb must step on mid and then break the loop
                ub = mid;
            }else{
                // [0, 0, 0, 0, 1, 1, 1]
                //           ^ mid
                lb = mid+1;
            }
        }
        return lb;
    }
};
