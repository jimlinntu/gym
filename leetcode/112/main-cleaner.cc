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
    bool solve(TreeNode *root, int cur_sum, int t){
        if(root == nullptr) return false;
        // is a child
        cur_sum += root->val;
        if(root->left == nullptr and root->right == nullptr)
            return cur_sum == t;
        return solve(root->left, cur_sum, t) or solve(root->right, cur_sum, t);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, 0, targetSum);
    }
};
