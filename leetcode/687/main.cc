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
    int maxNodes;
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root == nullptr) return 0;
        maxNodes = 0;
        solve(root);
        return maxNodes-1;
    }
    
    int solve(TreeNode *cur){
        // left, right indicate the maximum nodes 
        // from cur->left or cur->right to their children
        int left = 0, right = 0, ret;
        if(cur->left != nullptr){
            ret = solve(cur->left);
            if(cur->val == cur->left->val) left = max(left, ret);
        }
        if(cur->right != nullptr){
            ret = solve(cur->right);
            if(cur->val == cur->right->val) right = max(right, ret);
        }
        maxNodes = max(maxNodes, 1+left+right); // concatenate left and right branches
        // return the maximum nodes from this current node to a child
        return max(left+1, right+1);
    }
};
