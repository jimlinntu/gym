/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // solve(root) == find p or q
    TreeNode* solve(TreeNode *root,
                           TreeNode *p,
                           TreeNode *q){
        if(root == nullptr) return nullptr;
        // NOTE: If p is under q, we will not be able to "touch" q,
        //       but knowing p will be enough for us
        // Case 1: p is under q or q is under p
        if(root == p) return root;
        if(root == q) return root;
        // Case 2: p and q are on under r (r != p, r != q)
        TreeNode *l = solve(root->left, p, q);
        TreeNode *r = solve(root->right, p, q);
        if(l != nullptr and r != nullptr) return root;
        // there is p or q on the left
        if(l) return l;
        else if(r) return r;
        return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};
