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
    void dp_flatten_O_one(TreeNode *root){
        // Morris traversal algorithm
        // Time Complexity: O(n)
        // Because cur will at most visit O(n) nodes, so as left_last
        if(root == nullptr) return;
        TreeNode *cur = root;
        while(cur != nullptr){
            TreeNode *left_last = cur->left;
            // Go as right as possible
            while(left_last != nullptr and left_last->right != nullptr){
                left_last = left_last->right;
            }
            // Put things on the right under left_last
            if(left_last != nullptr){
                left_last->right = cur->right;
                // Move the whole left subtree to the right
                cur->right = cur->left;
                cur->left = nullptr;
            }
            // Move on
            cur = cur->right;
        }
    }
    void flatten(TreeNode* root) {
        dp_flatten_O_one(root);
        return;
    }
};
