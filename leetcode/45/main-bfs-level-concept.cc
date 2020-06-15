class Solution {
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return 0;
        int level = 0;
        int start = 0, end = 1;
        int farest = -1;
        // Note: you can achieve 8ms by commenting out start < end
        // But testing if start < end can work in nonreachable case too
        while(start < end){
            level++;
            // Expand all nodes in [start, end)
            for(int i = start; i < end; i++){
                // Expand the rightmost index that can be reached
                farest = max(farest, i+nums[i]);
                if(farest >= n-1) return level;
            }
            start = end;
            end = farest+1;
        }
        return -1;
    }
};
