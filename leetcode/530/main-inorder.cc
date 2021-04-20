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
    int inorder(TreeNode *root){
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        stack<TreeNode*> s;
        int min_dist = -1;
        while(cur != nullptr or !s.empty()){
            while(cur != nullptr){
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(prev != nullptr){
                if(min_dist == -1) min_dist = cur->val - prev->val;
                else min_dist = min(min_dist, cur->val - prev->val);
            }
            prev = cur;
            // Move on
            cur = cur->right;
        }
        return min_dist;
    }
    int getMinimumDifference(TreeNode* root) {
        return inorder(root);
    }
};
