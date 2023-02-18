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
    int ans;
    TreeNode *prev;
    void traverse(TreeNode *cur){
        if(cur == nullptr) return;
        traverse(cur->left);
        if(prev != nullptr){
            ans = min(ans, cur->val - prev->val);
        }
        prev = cur;
        traverse(cur->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        ans = numeric_limits<int>::max();
        prev = nullptr;
        traverse(root);
        return ans;
    }
};
