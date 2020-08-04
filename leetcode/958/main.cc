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
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool miss = false;
        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                TreeNode *cur = q.front();
                q.pop();
                if(cur->left){
                    if(miss){
                        return false;
                    }else q.push(cur->left);
                }else{
                    miss = true;
                }
                
                if(cur->right){
                    if(miss){
                        return false;
                    }else q.push(cur->right);
                }else{
                    miss = true;
                }
            }
        }
        return true;
    }
};
