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
    TreeNode* convertBST(TreeNode* root) {
        int cursum = 0;
        TreeNode *cur = root;
        TreeNode *left, *right;
        stack<TreeNode*> stk;
        while(cur != nullptr or !stk.empty()){
            // To the rightmost
            while(cur != nullptr){
                stk.push(cur);
                cur = cur->right;
            }
            cur = stk.top();
            stk.pop();
            cursum += cur->val;
            cur->val = cursum;

            cur = cur->left;
        }
        return root;
    }
};
