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


void merge(TreeNode *t, TreeNode *other){
    t->val += other->val; // add the current root
    if(other->left != nullptr){
        if(t->left != nullptr){
            merge(t->left, other->left);
        }else{
            t->left = other->left; // concatenate other->left's subtree
        }
    }
    
    if(other->right != nullptr){
        if(t->right != nullptr){
            merge(t->right, other->right);
        }else{
            t->right = other->right; // concat other->right's subtree
        }
    }
}
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // if one is nullptr, just return the other tree
        if(t2 == nullptr) return t1;
        if(t1 == nullptr) return t2;
        merge(t1, t2);
        return t1;
    }
};
