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
    TreeNode* clone_tree(TreeNode *root, int offset){
        if(root == nullptr) return nullptr;
        TreeNode *l = clone_tree(root->left, offset);
        TreeNode *r = clone_tree(root->right, offset);
        return new TreeNode(root->val + offset, l, r);
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> roots(n+1);
        roots[0] = {nullptr};
        for(int i = 1; i <= n; i++){
            // Every number can possibly become a root
            for(int j = 1; j <= i; j++){
                // Consider every combination of (left, right)
                for(TreeNode *left: roots[j-1]){
                    for(TreeNode *right: roots[i-j]){
                        // NOTE: We can reuse the left
                        //       because that tree's values are the same!
                        //       But we will have to clone the right tree
                        TreeNode *cloned_left = left;
                        TreeNode *cloned_right = clone_tree(right, j);
                        roots[i].push_back(
                            new TreeNode(j, cloned_left, cloned_right));
                    }
                }
            }
        }
        return roots[n];
    }
};
