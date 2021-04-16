class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int m = firstList.size();
        int n = secondList.size();
        if(m == 0 or n == 0) return {};
        vector<vector<int>> ans;
        for(int i = 0, j = 0; i < m and j < n;){
            int fmin = firstList[i][0], fmax = firstList[i][1];
            int smin = secondList[j][0], smax = secondList[j][1];
            int inter_min = max(fmin, smin), inter_max = min(fmax, smax);
            if(inter_min <= inter_max) ans.push_back({inter_min, inter_max});
            if(fmax < smax){
                // it is still possible for [smin, smax] to intersact the firstList
                i++;
            }else if(fmax > smax){
                // it is still possible for [fmin, fmax] to intersact the secondList
                j++;
            }else{
                // we can move i, j both
                i++, j++;
            }
        }
        return ans;
    }
};
