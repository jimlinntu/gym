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
    tuple<int, int, int> solve(TreeNode *root){
        // empty node is always covered
        if(root == nullptr)
            return {INT_MAX, 0, INT_MAX};
        // Case 1: has a camera on this node
        // Case 2: has no camera on this node, but is covered
        // Case 3: has no camera on this node, and is not covered
        //         (expect its parent will save him)
        auto [l1, l2, l3] = solve(root->left);
        auto [r1, r2, r3] = solve(root->right);

        // Case 1: has a camera on this node
        int ret1, ret2 = INT_MAX, ret3 = INT_MAX;
        ret1 = 1 + min({l1, l2, l3}) + min({r1, r2, r3});
        // Case 2:
        // left or right child contains a camera
        if(root->left)
            ret2 = min(ret2, l1 + min(r1, r2));
        if(root->right)
            ret2 = min(ret2, r1 + min(l1, l2));
        // Case 3:
        // children must have been covered
        if(l2 != INT_MAX and r2 != INT_MAX)
            ret3 = l2 + r2;

        return {ret1, ret2, ret3};
    }
    int minCameraCover(TreeNode* root) {
        auto [a1, a2, a3] = solve(root);
        return min(a1, a2);
    }
};
