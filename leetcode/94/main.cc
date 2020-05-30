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

void get_inorder(TreeNode *current, vector<int> &seq){
    if(current == nullptr) return;
    // all the way to the left
    get_inorder(current->left, seq);
    seq.push_back(current->val);
    get_inorder(current->right, seq);
    return;
}

void get_inorder_iter(TreeNode *root, vector<int> &seq){
    TreeNode *current = root;
    stack<TreeNode*> s;
    while(current != nullptr or !s.empty()){
        // all the way to the leftest node
        while(current != nullptr){
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        seq.push_back(current->val);
        current = current->right;
    }
}
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> seq;
        get_inorder_iter(root, seq);
        return seq;
    }
};
