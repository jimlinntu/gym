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
    // O(log n) extra space (considering the height of the program stack)
    // dp_flatten will return the last node after flattened
    TreeNode* dp_flatten(TreeNode *cur){
        TreeNode *left_last = cur, *right_last = nullptr;
        if(cur->left != nullptr){
            left_last = dp_flatten(cur->left);
        }
        if(cur->right != nullptr){
            right_last = dp_flatten(cur->right);
        }
        // Here, our left and right subtree are already flattened
        // Concatenate the left flatten subtree and the right flatten subtree
        if(cur->left != nullptr){
            TreeNode *left = cur->left;
            TreeNode *right = cur->right;
            cur->right = left;
            left_last->right = right;
            
            cur->left = nullptr;
        }
        return (right_last != nullptr)?(right_last):(left_last);
    }
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        dp_flatten(root);
        return;
    }
};
