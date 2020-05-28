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

int get_depth(TreeNode *current){
    if(current == nullptr) return 0;
    int left_depth = get_depth(current->left);
    int right_depth = get_depth(current->right);
    return ((left_depth < right_depth)? (right_depth):(left_depth))+1;
}
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return get_depth(root);
    }
};
