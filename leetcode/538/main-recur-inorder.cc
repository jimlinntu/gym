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
    int cursum = 0;
    // Inorder traversal
    TreeNode* solve(TreeNode *root){
        if(root == nullptr) return nullptr;
        TreeNode *right = solve(root->right);
        cursum += root->val;
        TreeNode *ret = new TreeNode(cursum);
        TreeNode *left = solve(root->left);
        ret->left = left;
        ret->right = right;
        return ret;
    }
    TreeNode* convertBST(TreeNode* root) {
        return solve(root);
    }
};
