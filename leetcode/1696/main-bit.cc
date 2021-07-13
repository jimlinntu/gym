// imagine a virtual array: a (1-indexed)
// we do this: a[i] = max(a[i], v)
void add(vector<int> &bit, int i, int v){
    i++; // 1-based
    // propgate this information left
    for(; i > 0; i -= i & (-i)){
        bit[i] = max(bit[i], v);
    }
}

// get the suffix max over a virtual array a
// i.e. max(a[i:])
int get(vector<int> &bit, int i){
    int res = INT_MIN;
    i++; // 1-based
    for(; i < bit.size(); i += i & (-i)){
        res = max(res, bit[i]);
    }
    return res;
}

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        // imagine the virtual array is 1-based
        vector<int> bit(n+k+1, INT_MIN);
        // a[i] = 0 because dp[0] = nums[0] + 0
        add(bit, 0, 0);
        // dp[i]
        int dp_i;
        for(int i = 0; i < n; i++){
            int maximum = get(bit, i);
            // dp[i] = nums[i] + max({dp[i-j]}) where 1 <= j <= k
            dp_i = nums[i] + maximum;
            // put dp_i at i+k so that every j <= i+k
            // will "see" it when we compute the suffix max
            add(bit, i+k, dp_i);
        }
        return dp_i;
    }
};
