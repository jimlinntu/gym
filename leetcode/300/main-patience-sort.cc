class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int length = 0; // length of the piles
        vector<int> piles(n); // pile[i] == i-th pile's top card
        
        // simulate drawing a card for the deck
        for(auto card:nums){
            // if the length of piles is zero or
            // the biggest card can not be >= than the current card,
            // create a new pile
            // Otherwise, perform a binary search
            if(length == 0 or piles[length-1] < card){
                piles[length++] = card;
            }else{
                // search for the leftmost pile that fits
                int l = 0, r = length-1;
                int mid = (l+r)/2;
                while(l < r){
                    mid = (l+r)/2;
                    // if the top card of this pile is smaller than this card,
                    // we should move right
                    if(piles[mid] < card){
                        l = mid+1;
                    }
                    // if this the pile on the left is >= card,
                    // we should keep searching the left part
                    else if(mid - 1 >= 0 and piles[mid-1] >= card){
                        r = mid-1;
                    }else{
                        l = r = mid;
                    }
                }
                // put the card on this pile
                piles[l] = card;
            }
        }
        return length;
    }
};
