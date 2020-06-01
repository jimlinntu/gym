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
    TreeNode *current;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        current = root;
        _prepare();
    }
    void _prepare(){
        // all the way to the leftest node
        while(current != nullptr){
            s.push(current);
            current = current->left;
        }
    }
    /** @return the next smallest number */
    int next() {
        TreeNode* top = s.top();
        s.pop();
        if(top->right != nullptr){
            current = top->right;
            _prepare();
        }
        return top->val;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
