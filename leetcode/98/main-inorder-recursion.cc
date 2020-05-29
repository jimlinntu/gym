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


/*
    Idea: For each current node, record the right_most (from the perspective of inorder projection) node on the left
    So the function will return the right most node for this subtree
*/
TreeNode * inorder(TreeNode *current, TreeNode *right_most, bool &ans){
    if(!ans) return nullptr;
    if(current == nullptr){
        return right_most; // preserve the same right most node
    }
    if(current->left != nullptr){
        // update the right most node after current->left subtree finished
        right_most = inorder(current->left, right_most, ans);
    }
    // if there is a right most node, this value must be smaller than this current->val
    if(right_most != nullptr){
        if(!(right_most->val < current->val)){
            ans = false;
        }
    }
    // set the initial right most node for the right child
    right_most = current;
    if(current->right != nullptr){
        // update the right most node after current->right subtree finished
        right_most = inorder(current->right, right_most, ans);
    }
    return right_most;
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        inorder(root, nullptr, ans);
        return ans;
    }
};
