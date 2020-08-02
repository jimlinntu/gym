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
    void search(TreeNode *cur, int depth, int &min_depth){
        if(cur->left == nullptr and cur->right == nullptr){
            if(min_depth == -1){
                min_depth = depth;
            }else min_depth = min(min_depth, depth);
        }
        // depth pruning: if the depth already exceeds the minimum nodes, break
        if(min_depth != -1 and depth > min_depth) return;
        if(cur->left) search(cur->left, depth+1, min_depth);
        if(cur->right) search(cur->right, depth+1, min_depth);
        return;
    }
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int min_depth = -1;
        search(root, 0, min_depth);
        return min_depth+1;
    }
};
