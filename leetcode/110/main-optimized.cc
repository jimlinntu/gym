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

int get_depth(TreeNode *current){
    int left_depth = 0, right_depth = 0;
    if(current->left != nullptr){
        // the depth of the left subtree
        left_depth = get_depth(current->left);
        if(left_depth == -1) return -1; // -1 indicate unbalanced
    }
    if(current->right != nullptr){
        // the depth of the right subtree
        right_depth = get_depth(current->right);
        if(right_depth == -1) return -1;
    }
    
    int max_depth = (left_depth < right_depth)? (right_depth):(left_depth);
    if(max_depth - left_depth > 1 or max_depth - right_depth > 1){
        return -1; // unbalanced
    }
    return max_depth+1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        return get_depth(root) != -1;
    }
};
