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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        if(root->left == nullptr){
            flatten(root->right);
        }else if(root->right == nullptr){
            root->right = root->left;
            root->left = nullptr;
            flatten(root->right);
        }else{
            TreeNode *cur = root->left;
            while(cur->right != nullptr){
                cur = cur->right;
            }
            // Concatenate the right tree to here
            cur->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            flatten(root->right);
        }
    }
};
