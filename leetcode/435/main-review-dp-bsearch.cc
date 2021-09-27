class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &l, const vector<int> &r){
            return l[1] < r[1];
        });
        int n = intervals.size();
        // dp[i] == the maximum number of intervals
        //          we can put from 0~i
        vector<int> dp(n);
        dp[0] = 1; // no conflict, directly put it in
        // O(n log n)
        for(int i = 1; i < n; i++){
            int start = intervals[i][0], end = intervals[i][1];
            // not choose it
            dp[i] = dp[i-1];
            // choose it
            // Bsearch by the end time
            // (upper bound)
            // find the first end time > start
            // Ex. end times: 1, 2, 2, 3
            int l = 0, r = i;
            while(l < r){
                int mid = (l+r)/2;
                if(intervals[mid][1] <= start){
                    l = mid+1;
                }else if(intervals[mid][1] > start){
                    r = mid;
                }
            }
            if(l > 0) dp[i] = max(dp[i], dp[l-1]+1);
        }
        return n-dp[n-1];
    }
};
