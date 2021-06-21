int log2(int x){
    int original_x = x;
    assert(x > 0);
    int count = 0;
    while((x >>= 1) > 0){
        count++;
    }
    // Ex. 01001 => 10000
    if((1 << count) < original_x) count++;
    return count;
}
struct SegTree{
    unordered_map<int, int> axis2idx;
    unordered_map<int, int> idx2axis;
    int prev_height;
    int size = 0;
    // tree[i] == 1) -1 if this range does not have unified heights
    //            2) the maximum height of this range
    vector<int> tree;

    SegTree(set<int> &xs){
        for(int x: xs){
            axis2idx[x] = size;
            idx2axis[size] = x; // map the index back to axis
            size++;
        }
        
        // Make size the power of 2
        size = 1 << log2(size);
        // 2*size
        // tree[0] == dummy
        // tree[1] == the root
        // tree[2], tree[3] == the children of the root
        tree = vector<int>(2 * size, 0);
    }
    // Put the h in [l, r) range
    void update(int l, int r, int h){
        // NOTE: [l, r), that's why we subtract it by 1 here
        int left = axis2idx[l], right = axis2idx[r]-1;
        assert(left <= right);
        // node range:   [0, size-1]
        // update range: [left, right]
        _update(1, 0, size-1, left, right, h);
    }

    void _update(int i, int node_left, int node_right,
                 int left, int right, int h){
        // [left, right] < [node_left, node_right]
        if(right < node_left) return;
        // [node_left, node_right] < [left, right]
        if(left > node_right) return;
        // Ex. [0, 3] -> [0, 1], [2, 3]
        int mid = (node_left + node_right) / 2;
        // 1. Perfectly aligned
        // 2. Not aligned
        // [node_left, node_right] == [left, right]
        if(node_left == left and node_right == right){
            if(tree[i] == -1){
                // This range's heights are fragmented
                // we have to traverse its children
                _update(2*i, node_left, mid, left, mid, h);
                _update(2*i+1, mid+1, node_right, mid+1, right, h);
            }else if(tree[i] < h){
                // This new building can overthrone the original height
                tree[i] = h;
            }
        }else{
            if(tree[i] == -1){
            }else if(tree[i] >= h){
                // if this range's height is already >=, do nothing
                return;
            }else if(tree[i] < h){
                // if this new builiding can give bigger height
                // we first give this height to its children
                // and then update its children
                assert(2*i < tree.size());
                assert(2*i+1 < tree.size());
                tree[2*i] = tree[i];
                tree[2*i+1] = tree[i];
                tree[i] = -1; // invalid this range's height;
            }
            _update(2*i, node_left, mid, left, min(right, mid), h);
            _update(2*i+1, mid+1, node_right, max(mid+1, left), right, h);
        }
    }

    // traverse the tree
    void output(vector<vector<int>> &ans){
        prev_height = 0; // ground
        _output(1, 0, size-1, ans);
    }
    
    void _output(int i, int node_left, int node_right,
                 vector<vector<int>> &ans){
        // debugging
        if(node_left == node_right) assert(tree[i] >= 0);
        if(tree[i] >= 0){
            // if this is the padding index, we will break
            if(idx2axis.find(node_left) == idx2axis.end()) return;
            
            if(prev_height != tree[i]) ans.push_back({idx2axis[node_left], tree[i]});
            prev_height = tree[i]; // update the height
        }else{
            int mid = (node_left + node_right) / 2;
            // Go left
            _output(2*i, node_left, mid, ans);
            // Go right
            _output(2*i+1, mid+1, node_right, ans);
        }
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> xs;
        // Get all possible x axis
        for(auto &b: buildings){
            xs.insert(b[0]);
            xs.insert(b[1]);
        }

        SegTree seg_tree(xs);
        // Build the skyline via the Segment Tree
        for(auto &b: buildings){
            seg_tree.update(b[0], b[1], b[2]);
        }
        // Output
        vector<vector<int>> ans;
        seg_tree.output(ans);
        return ans;
    }
};
