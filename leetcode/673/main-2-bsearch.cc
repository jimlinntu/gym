int find_insert_idx(int card, vector<vector<int>> &piles, int length){
    // the numbers on top of each pile will form an increasing seq
    // Ex. 1 2 3 4 5 7
    //         ^ (if card == 3)
    int l = 0, r = length, mid;
    while(l < r){
        mid = (l+r)/2;
        if(piles[mid].back() < card){
            l = mid+1; // move right
        }else{
            r = mid; // move left
        }
    }
    assert(l != length);
    return l;
}
int get_num(int card, vector<int> &pile, vector<int> &pre){
    // Find the rightmost number such that all numbers on its right side should be <= than card
    // pile is in decreasing order
    //
    // Ex.  6 5 4 4 3 2 1
    // pre: 1 1 2 3 4 6 8
    //              ^ (index == 4, if card == 4)
    // total == 8 - 3 == pre.back() - pre[4-1]

    assert(pile.size() == pre.size());
    int total = pre.back();
    int n = pile.size();
    int l = 0, r = n, mid;
    while(l < r){
        mid = (l+r)/2;
        if(pile[mid] >= card){
            l = mid+1;
        }else{
            r = mid; // pile[mid] < card, keep move left
        }
    }
    
    if(l > 0) total -= pre[l-1];
    assert(l != n); // pile.back() must < card
    assert(pile.back() < card);
    
    return total;
}

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int length = 0; // longest increasing subsequece length
        // piles[i] == the i-th pile, piles[i].back() is the top of piles[i]
        vector<vector<int>> piles(n);
        // piles[i] == the i-th pile's prefix sum,
        // piles[i][j] indicates sum(piles[i] from 0 to j)
        // Intuition: given a number k,
        //            we can access the total number of
        //            (num <= k for num in piles[i]) by
        //            presum[i].back() - presum[i][j-1],
        //            where j is the first element in piles[i] that is <= than k
        vector<vector<int>> presum(n);
        for(auto card: nums){
            int i;
            int num_options;
            if(length == 0 or piles[length-1].back() < card){
                i = length++;
            }else{
                i = find_insert_idx(card, piles, length);
            }
            // compute the number of possible options
            if(i > 0) num_options = get_num(card, piles[i-1], presum[i-1]);
            else num_options = 1; // itself is a IS with length 1
            piles[i].push_back(card);

            // add prefix sum
            if(presum[i].size() == 0) presum[i].push_back(num_options);
            else{
                num_options += presum[i].back();
                presum[i].push_back(num_options);
            }
        }
        return presum[length-1].back();
    }
};
