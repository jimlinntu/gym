class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return true;
        int start = 0, end = 1;
        int farest = -1;
        // Perform BFS
        while(start < end){
            // Expand this level's node
            for(int i = start; i < end; i++){
                farest = max(farest, i+nums[i]);
                if(farest >= n-1) return true;
            }
            
            start = end;
            end = farest+1;
        }
        return false;
    }
};
