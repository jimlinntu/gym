class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n == 0) return ans;
        // O(n log n)
        sort(intervals.begin(), intervals.begin()+n);
        // Two loops but in O(n) time
        // Because we will only visit each interval once
        for(int i = 0; i < n;){
            int j = i+1;
            int cur_min = intervals[i][0], cur_max = intervals[i][1];
            // If this can be merged
            while(j < n and intervals[j][0] <= cur_max){
                // merge the [cur_min, cur_max] and intervals[j]
                cur_max = max(cur_max, intervals[j][1]);
                j++;                
            }
            ans.push_back({cur_min, cur_max});
            i = j;
        }
        return ans;
    }
};
