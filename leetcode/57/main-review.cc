class Solution {
public:
    bool is_overlap(vector<int> &inter, vector<int> &newInter){
        int start = max(inter[0], newInter[0]);
        int end = min(inter[1], newInter[1]);
        if(start <= end) return true;
        return false;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        // Case 1:
        // |    |          |   |
        //         |    |
        // Case 2:
        // |    |          |   |
        //    |              |
        // Case 3:
        // |    |          |   |
        //          |        |
        // Case 4:
        // |    |          |   |
        //    |       |
        bool added = false;
        int n = intervals.size();
        for(int i = 0; i < n; i++){
            if(added){
                assert(ans.size() > 0);
                // merged with the previous one
                if(intervals[i][0] <= ans.back()[1]){
                    ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                }else{
                    ans.push_back(intervals[i]);
                }
            }else{
                // Case 1:
                if(newInterval[1] < intervals[i][0]){
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    added = true;
                }else if(is_overlap(intervals[i], newInterval)){
                    int merged_start = min(intervals[i][0], newInterval[0]);
                    int merged_end = max(intervals[i][1], newInterval[1]);
                    ans.push_back({merged_start, merged_end});
                    added = true;
                }else{
                    ans.push_back(intervals[i]);
                }
            }
        }

        if(!added) ans.push_back(newInterval);
        
        return ans;
    }
};
