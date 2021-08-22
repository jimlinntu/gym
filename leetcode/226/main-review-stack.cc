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
        if(root == nullptr) return root;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode *cur = stk.top();
            stk.pop();
            swap(cur->left, cur->right);

            if(cur->left) stk.push(cur->left);
            if(cur->right) stk.push(cur->right);
        }
        return root;
    }
};
