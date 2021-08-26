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
struct R{
    int min, max;
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        while(cur or !stk.empty()){
            // Go as left as possible
            while(cur != nullptr){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            // visit this node
            if(prev and prev->val >= cur->val) return false;
            prev = cur;
            cur = cur->right;
        }
        return true;
    }
};
