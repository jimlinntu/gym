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
    // Perform postorder traversal
    void del(TreeNode *root, bool is_to_delete[], vector<TreeNode*> &ans){
        if(root->left != nullptr) del(root->left, is_to_delete, ans);
        if(root->right != nullptr) del(root->right, is_to_delete, ans);

        // Clean up its children
        if(root->left != nullptr and is_to_delete[root->left->val]){
            delete root->left;
            root->left = nullptr;
        }
        if(root->right != nullptr and is_to_delete[root->right->val]){
            delete root->right;
            root->right = nullptr;
        }
        if(is_to_delete[root->val]){
            if(root->left != nullptr) ans.push_back(root->left);
            if(root->right != nullptr) ans.push_back(root->right);
            // leave the cleanup for its parent
            // Edge case: the top root will not be deleted
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == nullptr) return {};
        vector<TreeNode*> ans;
        bool is_to_delete[1001] = {false};
        is_to_delete[0] = true; // dummy node will be deleted!
        for(int val: to_delete){
            is_to_delete[val] = true;
        }
        TreeNode dummy = TreeNode(0, root, nullptr);
        del(&dummy, is_to_delete, ans);
        return ans;
    }
};
