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

struct Nexter{
    stack<TreeNode*> stk;
    TreeNode *cur;
    Nexter(TreeNode *root){
        cur = root;
    }
    TreeNode *next(){
        while(cur != nullptr){
            stk.push(cur);
            cur = cur->left;
        }
        TreeNode *res = stk.top();
        stk.pop();
        cur = res->right;
        return res;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        Nexter nexter(root);
        TreeNode *cur;
        for(cur = nexter.next(); --k > 0; cur = nexter.next()){
        }
        return cur->val;
    }
};
