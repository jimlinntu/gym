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
            // Binary Search
            int l = 0, r = plen;
            while(l < r){
                int mid = (l+r)/2;
                if(pile[mid] < nums[i]){
                    l = mid+1;
                }else if(pile[mid] > nums[i]){
                    r = mid;
                }else{
                    r = mid;
                }
            }
            // not found
            if(l == plen){
                pile[plen++] = nums[i];
            }else{
                pile[l] = nums[i];
            }
        }
        return plen;
    }
};
