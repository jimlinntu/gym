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
class BSTIterator {
public:
    TreeNode *cur;
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        // Go as left as possible
        while(cur != nullptr){
            stk.push(cur);
            cur = cur->left;
        }
        TreeNode *ret = stk.top();
        stk.pop();
        cur = ret->right;
        return ret->val;
    }
    
    bool hasNext() {
        return cur != nullptr or !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
