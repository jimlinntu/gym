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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> s;
        if(root != nullptr) s.push(root);
        while(!s.empty()){
            TreeNode *cur = s.top();
            s.pop();
            swap(cur->left, cur->right);
            if(cur->right != nullptr) s.push(cur->right);
            if(cur->left != nullptr) s.push(cur->left);
        }
        return root;
    }
};
