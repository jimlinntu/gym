class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0;
        // An edge case: handle it separately
        if(goal == 0){
            // [0, 0, 0, 0, 0, 1, 0, 0, 0]
            int num_zero = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0){
                    num_zero++;
                    ans += num_zero; // `num_zero` subarray ending at i
                }else{
                    num_zero = 0; // reset
                }
            }
            return ans;
        }
        vector<int> indices;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) indices.push_back(i);
        }
        int n = nums.size();
        // [0, 0, 1, 0, 1, 0, 0, 1, 1]
        //        i     j
        //  *  *  *     *  *  *
        //  ^^^^^^^     ^^^^^^^
        //  left_count  right_count
        for(int i = 0; i < indices.size(); i++){
            int j = i+goal-1;
            if(j >= indices.size()) break; // no way to form a subarray of sum `goal`

            // [indices[i], indices[j]] forms a subarray of sum == goal
            // Imagine expand indices[i] to the left until we reach a 1
            // Same idea applies to the right
            // i.e. [indices[i], indices[j]]
            // left side can be expanded to indices[i-1]+1
            // and right side can be expanded to indices[j+1]-1
            
            int left_count;
            if(i-1 >= 0) left_count = indices[i]-indices[i-1];
            else left_count = indices[i]+1;

            int right_count;
            if(j+1 < indices.size()) right_count = indices[j+1]-indices[j];
            else right_count = n-indices[j];

            ans += left_count * right_count;
        }
        return ans;
    }
};
