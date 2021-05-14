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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int kk = k;
        TreeNode *cur = root;
        while(!stk.empty() or cur != nullptr){
            while(cur != nullptr){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            kk--;
            if(kk == 0) return cur->val;
            cur = cur->right;
        }
        return -1;
    }
};
