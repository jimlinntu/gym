class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // sort by its start time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        if(n == 0) return ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            // overlap
            if(start <= ans.back()[1]){
                // merge
                ans.back()[1] = max(ans.back()[1], end);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
