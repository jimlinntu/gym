
class NumArray {
public:
    int n; // # of elements
    vector<int> a;
    vector<int> bit; // bit.size() == n+1

    void update(int i, int v){
        // propagate to the right
        for(; i <= n; i += i & (-i)){
            bit[i] += v;
        }
    }

    // sum(a from 0 to i-1) (a is 0-index)
    int query(int i){
        int s = 0;
        // get information to the left
        for(; i > 0; i -= i & (-i)){
            s += bit[i];
        }
        return s;
    }

    NumArray(vector<int>& nums) {
        a = move(nums);
        n = a.size();
        bit = vector<int>(n+1, 0);

        for(int i = 0; i < n; i++){
            // 1-index
            update(i+1, a[i]);
        }
    }

    int sumRange(int left, int right) {
        // 0-index -> 1-index
        int s1 = query(right+1);
        int s2 = query(left+1-1);
        return s1-s2;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
