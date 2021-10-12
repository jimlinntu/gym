class Solution {
public:
    // find the first interval where its end >= start
    int find_lb(vector<vector<int>> &intervals, int start){
        int l = 0, r = intervals.size();
        while(l < r){
            int mid = (l+r)/2;
            int e = intervals[mid][1];
            if(e < start){
                l = mid+1;
            }else if(e >= start){
                r = mid;
            }
        }
        return l;
    }
    // find the first interval where its start > end
    int find_ub(vector<vector<int>> &intervals, int end){
        int l = 0, r = intervals.size();
        while(l < r){
            int mid = (l+r)/2;
            int s = intervals[mid][0];
            if(s <= end){
                l = mid+1;
            }else if(s > end){
                r = mid;
            }
        }
        return l;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = newInterval[0], end = newInterval[1];
        int i = 0;
        vector<vector<int>> ans;
        // For every i >= l, intervals[i][1] >= start
        int l = find_lb(intervals, start);
        // For every i < r, intervals[i][0] <= end
        // Therefore, for every l <= i < r,
        // start <= intervals[i][1] and intervals[i][0] <= end
        // => have overlapped region!!
        int r = find_ub(intervals, end);
        for(int i = 0; i < l; i++){
            ans.push_back(intervals[i]);
        }
        for(int i = l; i < r; i++){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
        }
        ans.push_back({start, end});
        for(int i = r; i < n; i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
