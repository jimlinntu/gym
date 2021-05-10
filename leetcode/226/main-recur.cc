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
    void invert(TreeNode *cur){
        if(cur == nullptr) return;
        invert(cur->left);
        invert(cur->right);
        swap(cur->left, cur->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
