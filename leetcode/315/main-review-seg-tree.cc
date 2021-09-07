class Solution {
public:
    void update(vector<int> &tree, int idx, int val){
        // update all their parents
        idx += tree.size()/2;
        for(; idx > 0; idx /= 2){
            tree[idx] += val;
        }
    }
    int query(vector<int> &tree, int l, int r){
        int ans = 0;
        // move to the leaves
        l += tree.size()/2;
        r += tree.size()/2;
        while(l <= r){
            if(l % 2 == 1) ans += tree[l++];
            if(r % 2 == 0) ans += tree[r--];
            l /= 2, r /= 2;
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        // integer to index
        unordered_map<int, int> map;
        int n = 0;
        for(int i = 0; i < copy.size(); i++){
            if(i == 0 or copy[i-1] != copy[i]){
                map[copy[i]] = n++; // 0-index
            }
        }
        // make it a power of 2
        n = 1 << (int)ceil(log2(n));
        vector<int> tree(2*n, 0);
        int nn = nums.size();
        vector<int> ans(nn);
        for(int i = nn-1; i >= 0; i--){
            // [0, idx) are the numbers smaller than me
            ans[i] = query(tree, 0, map[nums[i]]-1);
            update(tree, map[nums[i]], 1);
        }
        return ans;
    }
};
