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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int i = 0, j = 0;
        TreeNode fake_root;
        TreeNode *parent = &fake_root;
        stack<TreeNode*> stk;
        while(i < n or j < n){
            while(i < n){
                TreeNode *cur = new TreeNode(preorder[i]);
                if(parent != nullptr){
                    parent->right = cur;
                    parent = nullptr;
                }else if(!stk.empty()) stk.top()->left = cur;

                stk.push(cur);
                if(preorder[i++] == inorder[j]) break;
            }

            while(!stk.empty() and j < n and stk.top()->val == inorder[j]){
                parent = stk.top();
                stk.pop();
                j++;
            }
            
        }
        return fake_root.right;
    }
};
