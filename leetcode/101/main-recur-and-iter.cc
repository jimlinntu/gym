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
    bool is_mirror_recursive(TreeNode *left, TreeNode *right){
        if(left == nullptr and right == nullptr) return true;
        // if only one side is nullptr, return false 
        if(left == nullptr) return false;
        if(right == nullptr) return false;
        // if the roots of each side do no meet, we will return false immediately
        if(left->val != right->val) return false;
        // if either side is not a mirror of the other side, we will return false immediately
        if(!is_mirror_recursive(left->left, right->right)) return false;
        if(!is_mirror_recursive(left->right, right->left)) return false;
        return true;
    }
    bool is_equal(TreeNode *l, TreeNode *r){
        if(l == nullptr and r == nullptr) return true;
        if(l == nullptr) return false;
        if(r == nullptr) return false;
        if(l->val != r->val) return false;
        return true;
    }
    bool is_mirror_iteratively(TreeNode *left, TreeNode *right){
        TreeNode *left_cur, *right_cur;
        stack<TreeNode*> left_stack;
        stack<TreeNode*> right_stack;
        left_stack.push(left);
        right_stack.push(right);
        while(!left_stack.empty() and !right_stack.empty()){
            left_cur = left_stack.top();
            left_stack.pop();
            right_cur = right_stack.top();
            right_stack.pop();
            // check the root
            if(!is_equal(left_cur, right_cur)) return false;
            if(left_cur != nullptr){
                // Place their childern into the stacks
                assert(right_cur != nullptr);
                // Notice: left_stack right_stack push left right in different orders
                left_stack.push(left_cur->right);
                left_stack.push(left_cur->left); // visit it first
                
                right_stack.push(right_cur->left);
                right_stack.push(right_cur->right); // visit it first
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return is_mirror_iteratively(root->left, root->right);
    }
};
