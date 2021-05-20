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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root != nullptr) q.push(root);
        while(!q.empty()){
            // depth-level traversal
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *cur = q.front();
                if(i == 0) ans.push_back(cur->val);
                q.pop();
                // Expand it from right to left
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
        }
        return ans;
    }
};
