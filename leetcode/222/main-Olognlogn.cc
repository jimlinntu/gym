/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int get_depth(TreeNode *root){
        if(root == nullptr) return 0;
        return get_depth(root->left)+1;
    }
    // check if this idx exists in O(log n) guided by the target nodes' idx
    bool exists(TreeNode *root, int idx, int cur_d, int tidx,
                int total_d){
        if(root == nullptr) return false;
        if(idx == tidx) return true;
        // Decide to go left or right
        // 1011 means: 0 (left) -> 1 (right) -> (right)
        bool go_right = tidx & (1 << (total_d-1-1-cur_d));

        if(go_right) return exists(root->right, 2*idx+1, cur_d+1, tidx, total_d);
        return exists(root->left, 2*idx, cur_d+1, tidx, total_d);
    }
    int countNodes(TreeNode* root) {
        // d == # of layers
        int d = get_depth(root);
        if(d <= 1) return d;
        // These we the nodes we must have
        // 2^0 + 2^1 + 2^2 ... 2^(d-2) = 1*(2^(d-1)-1) / (2-1) = 2^(d-1)
        // We still don't know have many nodes are in the last layer
        int count = (1 << (d-1))-1;
        // This binary tree is 1-index
        // i.e. 1 -- 2, 3 -- 4, 5, 6, 7
        // [l, r]: the leftmost in this layer, the rightmost in this layer
        int l = count+1, r = (1 << d)-1;
        // Binary search over the last layer: O(log^2 n)
        while(l <= r){
            int mid = (l+r)/2;
            bool ret = exists(root, 1, 0, mid, d);
            // Note:
            // Edge case: l == r
            if(ret) l = mid+1; // move left
            else r = mid-1;
        }
        // You can imagine the last layer is like
        // TTTTTTFFFF
        // where T represents a node
        // That's why we can perform a bsearch to find the rightmost T efficiently
        assert(r >= count+1);
        // r - the leftmost index + 1 == the number of nodes at this layer
        count += r-(count+1)+1;
        return count;
    }
};
