class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> pile(2, INT_MAX);
        // Patience sort: return when there is already 2 piles
        for(int i = 0; i < n; i++){
            int num = nums[i];
            // Put at the leftmost
            if(num <= pile[0]){
                pile[0] = num;
            }else if(num <= pile[1]){
                pile[1] = num;
            }else{
                // there is a third pile, we know the LIS >= 3 => return
                return true;
            }
        }
        return false;
    }
};
