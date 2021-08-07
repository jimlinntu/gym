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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> stk;
        if(root) stk.push({root, 1});
        TreeNode *cur;
        int depth;
        int ans = 0;
        while(!stk.empty()){
            tie(cur, depth) = stk.top();
            stk.pop();
            ans = max(ans, depth);
            if(cur->left) stk.push({cur->left, depth+1});
            if(cur->right) stk.push({cur->right, depth+1});
        }
        return ans;
    }
};
