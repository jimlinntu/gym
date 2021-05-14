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
struct TreeNodeWCount{
    int count;
    int val;
    TreeNodeWCount *left;
    TreeNodeWCount *right;
    TreeNodeWCount(int v){
        val = v;
        left = right = nullptr;
        count = 1;
    }
};
class Solution {
public:
    // O(h) (O(log n) in average, O(n) at worst)
    int solve(TreeNodeWCount *root, int k){
        if(root == nullptr) return -1;
        if(root->left){
            // it is just itself
            if(root->left->count == k-1) return root->val;
            // k-th is inside the left subtree
            if(root->left->count >= k) return solve(root->left, k);
            // k-th is inside the right subtree
            return solve(root->right, k-1-root->left->count);
        }else{
            // if there is no left subtree and k == 1,
            // it is just itself
            if(k == 1) return root->val;
            // k-th is inside the right subtree
            return solve(root->right, k-1);
        }
    }
    // O(n)
    TreeNodeWCount *build_tree(TreeNode *root){
        if(root == nullptr) return nullptr;
        // Clone root
        TreeNodeWCount *r = new TreeNodeWCount(root->val);
        r->left = build_tree(root->left);
        r->right = build_tree(root->right);
        if(r->left) r->count += r->left->count;
        if(r->right) r->count += r->right->count;
        return r;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNodeWCount *r = build_tree(root);
        return solve(r, k);
    }
};
