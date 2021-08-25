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
    vector<TreeNode*> v;
    bool issame(TreeNode *root, TreeNode *root2){
        if(root == nullptr and root2 == nullptr) return true;
        if(root == nullptr or root2 == nullptr) return false;
        
        if(root->val != root2->val) return false;
        return issame(root->left, root2->left) and \
            issame(root->right, root2->right);
    }
    unsigned digest(TreeNode *root){
        if(root == nullptr) return 0;
        return (digest(root->left) << 1) ^ (digest(root->right) << 2) ^ root->val;
    }
    
    unsigned hash_and_check(TreeNode *root, int hash2){
        if(root == nullptr) return 0;
        unsigned left = hash_and_check(root->left, hash2);
        unsigned right = hash_and_check(root->right, hash2);
        unsigned h = (left << 1) ^ (right << 2) ^ root->val;
        
        if(h == hash2) v.push_back(root);
        return h;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        unsigned hash2 = digest(subRoot);
        hash_and_check(root, hash2);
        
        for(TreeNode *cur: v){
            if(issame(cur, subRoot)) return true;
        }
        return false;
    }
};
