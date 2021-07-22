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
    bool is_balanced = true;
    int h(TreeNode *root){
        if(root == nullptr) return 0;
        int l = h(root->left);
        int r = h(root->right);
        if(abs(l-r) > 1) is_balanced = false;
        return 1+max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        h(root);
        return is_balanced;
    }
};
