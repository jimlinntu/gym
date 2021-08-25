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
        // tree -> root, left, right
        // tree -> left, root, right
        int n = preorder.size();
        TreeNode dummy;
        stack<TreeNode*> stk;
        int pidx = 0, iidx = 0;
        TreeNode *parent = &dummy;
        while(pidx < n){
            // Move pidx (go as left as possible until we encoutner inorder[idx])
            while(pidx < n and (stk.empty() or stk.top()->val != inorder[iidx])){
                TreeNode *cur = new TreeNode(preorder[pidx]);
                if(parent){
                    // the first time on a right branch
                    parent->right = cur;
                    parent = nullptr;
                }else{
                    stk.top()->left = cur; // go left
                }
                stk.push(cur);
                pidx++;
            }
            // Move iidx
            while(iidx < n and !stk.empty() and stk.top()->val == inorder[iidx]){
                parent = stk.top(); // save the latest
                stk.pop();
                iidx++;
            }
        }
        return dummy.right;
    }
};
