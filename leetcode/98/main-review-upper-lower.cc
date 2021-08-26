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
    bool solve(TreeNode *root, TreeNode *upper, TreeNode *lower){
        if(root == nullptr) return true;
        if(upper and root->val >= upper->val) return false;
        if(lower and root->val <= lower->val) return false;
        
        // left subtree's upper bound is this root
        if(!solve(root->left, root, lower)) return false;
        // right subtree's lower bound is this root
        if(!solve(root->right, upper, root)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root, nullptr, nullptr);
    }
};
