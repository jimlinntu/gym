class Solution {
public:
    // propagate the information to the right
    void update(vector<int> &bit, int i, int val){
        for(; i < bit.size(); i += i & (-i)){
            bit[i] += val;
        }
    }
    // prefix sum of array[1]~array[i]
    int query(vector<int> &bit, int i){
        int ans = 0;
        for(; i > 0; i -= i & (-i)){
            ans += bit[i];
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        // Ex. [2, 3, 3, 4, 6] --> {2: 1, 3: 2, 4: 3, 6: 4}
        // In other words, give each number an index
        unordered_map<int, int> map;
        int n = 0;
        for(int i = 0; i < copy.size(); i++){
            // unique numbers
            if(i == 0 or copy[i-1] != copy[i]){
                map[copy[i]] = ++n; // 1-index
            }
        }
        // Binary Indexed Tree
        vector<int> bit(n+1, 0);
        int nn = nums.size();
        vector<int> ans(nn);

        for(int i = nn-1; i >= 0; i--){
            // get how many numbers are smaller than me
            ans[i] = query(bit, map[nums[i]]-1);
            // Increment this number
            update(bit, map[nums[i]], 1);
        }
        return ans;
    }
};
