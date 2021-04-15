using Interval = vector<int>;

class Solution {
public:
    bool overlap(int l, int r, int ll, int rr){
        // Ex. [0, 5] and [2, 7]
        if(l <= ll and ll <= r) return true;
        // Ex. [0, 5] and [-2, 3]
        if(l <= rr and rr <= r) return true;
        // Ex. [0, 5] and [-1, 7]
        if(ll <= l and r <= rr) return true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<Interval> ans;
        int n = intervals.size();
        if(n == 0) return {newInterval};
        int new_min = newInterval[0], new_max = newInterval[1];
        int all_min = intervals[0][0], all_max = intervals[n-1][1];
        if(new_max < all_min) ans.push_back(newInterval);
        for(int i = 0; i < n;){
            int cur_min = intervals[i][0], cur_max = intervals[i][1];
            // If [cur_min, cur_max] and [new_min, new_max] overlap
            if(overlap(cur_min, cur_max, new_min, new_max)){
                int j = i+1;
                // merge from it to the right as far as possible
                cur_min = min(cur_min, new_min);
                cur_max = max(cur_max, new_max);
                // If [cur_min, cur_max] and intervals[j] overlap
                while(j < n and intervals[j][0] <= cur_max){
                    cur_max = max(cur_max, intervals[j][1]);
                    j++;
                }
                i = j;
            }else if(i-1 >= 0 and intervals[i-1][1] < new_min and new_max < cur_min){
                // [new_min, new_max] is in front of intervals[i]
                ans.push_back({new_min, new_max});
                i++;
            }else i++;

            ans.push_back({cur_min, cur_max});
        }
        // Edge case:
        if(all_max < new_min) ans.push_back(newInterval);
        return ans;
    }
};
