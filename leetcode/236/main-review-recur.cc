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
    TreeNode *solve(TreeNode *cur, TreeNode *p, TreeNode *q){
        if(cur == nullptr) return nullptr;
        if(cur == p) return p;
        if(cur == q) return q;
        
        TreeNode *left = solve(cur->left, p, q);
        TreeNode *right = solve(cur->right, p, q);
        // found
        if(left and right) return cur; 
        if(left) return left; // p or q is on the left
        if(right) return right; // p or q is on the right
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};
