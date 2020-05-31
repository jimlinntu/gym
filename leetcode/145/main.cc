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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> seq;
        TreeNode *current = root;
        TreeNode *parent;
        stack<TreeNode*> s;
        
        while(current != nullptr or !s.empty()){
            // all the way to the lft
            while(current != nullptr){
                s.push(current);
                current = current->left;
            }
            // probe the top of the stack
            current = s.top();
            if(current->right == nullptr){
                // the current node does not have a right child, we can visit this node
                seq.push_back(current->val);
                s.pop();
                // if current == parent->right, then pop parent as well
                // Concept: all the way back
                while(!s.empty() and current == s.top()->right){
                    current = s.top();
                    seq.push_back(current->val);
                    s.pop(); // pop the parent of the current node
                }
                // set current == nullptr so that we can skip pushing left children
                current = nullptr;
            }else{
                // move to the right child of the current node
                current = current->right;
            }
        }
        
        return seq;
    }
};
