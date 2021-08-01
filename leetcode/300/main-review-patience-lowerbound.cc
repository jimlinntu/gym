class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // Patience sort
        vector<int> pile(n); // at most n piles (Ex. 1 2 3 4 5)
        int plen = 0; // the length of the pile
        for(int i = 0; i < n; i++){
            // Put nums[i] to the leftmost pile
            // Find the first number that is at least >= nums[i]
            auto last = pile.begin()+plen;
            auto it = lower_bound(pile.begin(), last, nums[i]);
            if(it == last){
                pile[plen++] = nums[i]; // initialize a new pile
            }else{
                *it = nums[i]; // put this number on that pile
            }
        }
        return plen;
    }
};
