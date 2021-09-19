class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int start = v[0][0], end = v[0][1];
        vector<vector<int>> ans;
        int n = v.size();
        for(int i = 1; i < n; i++){
            int cur_start = v[i][0], cur_end = v[i][1];
            if(cur_start <= end){
                end = max(end, cur_end);
            }else{
                ans.push_back({start, end});
                start = cur_start;
                end = cur_end;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
