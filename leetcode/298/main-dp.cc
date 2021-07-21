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
    int max_len = 0;
    // the longest increasing seq starting from each subtree root
    int solve(TreeNode *root){
        if(root == nullptr) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int len = 1; // at least it self can form a seq of length 1
        if(root->left and root->val+1 == root->left->val)
            len = max(len, 1+l);
        if(root->right and root->val+1 == root->right->val)
            len = max(len, 1+r);

        max_len = max(max_len, len);
        return len;
    }
    int longestConsecutive(TreeNode* root) {
        solve(root);
        return max_len;
    }
};
