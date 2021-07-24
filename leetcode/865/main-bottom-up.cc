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


struct Ret{
    TreeNode *node;
    int d;
};

class Solution {
public:
    
    // Observe:
    // When left -- root -- right
    // 1) if the deepest node of left subtree is deeper than the deepest node of 
    // the right subtree, left subtree's root might be a possible candidate
    // 2) if the deepest node of left subtree is shallower than ...
    // 3) if left and right's subtree deepest node are of same length
    //    then the current root is a possible candidate
    // This prompt us that we should can store {TreeNode*, depth}
    Ret solve(TreeNode *root){
        if(root == nullptr){
            return {nullptr, 0};
        }
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        // 3)
        if(l.d == r.d) return {root, l.d+1};
        else if(l.d < r.d){
            // l.node must not be a candidate
            return {r.node, r.d+1};
        }else{
            // r.mode must not be a candidate
            return {l.node, l.d+1};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).node;
    }
};
