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
    vector<TreeNode*> candidates;
    size_t get_subtree_hash(TreeNode *root){
        if(root == nullptr) return 0;
        size_t hashed = 0;
        hashed ^= get_subtree_hash(root->left);
        hashed ^= get_subtree_hash(root->right) << 1;
        hashed ^= hash<int>()(root->val) << 2;
        return hashed;
    }
    size_t compute_tree_hash(TreeNode *root, size_t subtree_hash){
        if(root == nullptr) return 0;
        size_t hashed = 0;
        hashed ^= compute_tree_hash(root->left, subtree_hash);
        hashed ^= compute_tree_hash(root->right, subtree_hash) << 1;
        hashed ^= hash<int>()(root->val) << 2;
        // This is a possible candidate
        if(hashed == subtree_hash) candidates.push_back(root);
        return hashed;
    }
    bool check_equal(TreeNode *root, TreeNode *subRoot){
        if(root == nullptr and subRoot == nullptr) return true;
        if(root == nullptr or subRoot == nullptr) return false;
        if(root->val != subRoot->val) return false;
        return check_equal(root->left, subRoot->left) and
               check_equal(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        size_t subtree_hash = get_subtree_hash(subRoot);
        compute_tree_hash(root, subtree_hash);
        for(TreeNode *node: candidates){
            if(check_equal(node, subRoot)) return true;
        }
        return false;
    }
};
