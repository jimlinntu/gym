struct Interval{
    int start;
    int end;
    int profit;
    bool operator<(const Interval &r) const{
        return end < r.end;
    }
};
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Interval> v;
        for(int i = 0; i < n; i++){
            v.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(v.begin(), v.end());
        vector<int> dp(n);
        // Let dp[i] == the maximum profit using job from 0 to i
        dp[0] = v[0].profit;
        for(int i = 1; i < n; i++){
            // Not to choose it
            dp[i] = dp[i-1];
            // choose it
            // My bsearch: find the first element that is greater to v[i].start
            int l = 0, r = i;
            while(l < r){
                int mid = (l+r)/2;
                if(v[mid].end < v[i].start){
                    l = mid+1;
                }else if(v[mid].end > v[i].start){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            int j = l;
            dp[i] = max(dp[i], (j-1 >= 0)?(v[i].profit+dp[j-1]):(v[i].profit));
        }
        return dp[n-1];
    }
};
