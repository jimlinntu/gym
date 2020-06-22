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

int solve(TreeNode *current, int &maxValue){
    // because this current node might not consider left or right branches
    // we can safely set left = 0, and right = 0 as initial values
    int left = 0, right = 0;
    if(current->left != nullptr){
        left = max(left, solve(current->left, maxValue));
    }
    if(current->right != nullptr){
        right = max(right, solve(current->right, maxValue));
    }
    
    // if this current node is the highest node among the path,
    // what max value can this current node acheive
    // Note: originally, we should consider:
    // 1) cur, 2) cur + left, 3) cur + right 4) cur + left + right
    // But because I have already set left = 0, and right = 0 as initial values
    // we only need to consider cur + left + right
    // (i.e. cur + left + right >= max(cur, cur+left, cur+right, cur+left+right))
    maxValue = max(maxValue, current->val+left+right);
    
    // Note: we cannot consider current->val + left + right
    //       because we are considering a "path" from A to B in this tree
    return max(current->val+left, current->val+right);
}
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == nullptr) return -1;
        else{
            int maxValue = root->val; // at least will be root->val
            solve(root, maxValue);
            return maxValue;
        }
    }
};
