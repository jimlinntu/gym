int log2(int x){
    assert(x > 0);
    int xx = x;
    int power = 0;
    while((xx >>= 1) > 0){
        power++;
    }
    if(x > (1 << power)) power++;
    return power; // ceil(log2(x))
}

class NumArray {
public:
    int n;
    vector<int> tree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        // make n the power of 2
        n = 1 << log2(n);
        // tree[0]: dummy, tree[1] ... tree[n-1] internal nodes
        tree = vector<int>(2*n, 0);
        // Put numbers in the tree
        for(int i = 0; i < nums.size(); i++){
            update(i, nums[i]);
        }
    }

    void update(int index, int val) {
        // Start from the leaf node
        index += n;
        tree[index] = val;
        // update its parent
        for(index /= 2; index >= 1; index /= 2){
            tree[index] = tree[2*index] + tree[2*index+1];
        }
    }
    
    int sumRange(int left, int right) {
        // Starting from leaf nodes
        left += n, right += n;
        int s = 0;
        while(left <= right){
            // if left is on the right, it must be added now
            if(left % 2 == 1){
                s += tree[left++];
            }
            if(right % 2 == 0){
                s += tree[right--];
            }
            // move to the parent
            left /= 2, right /= 2;
        }
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
