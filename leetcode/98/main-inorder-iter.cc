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
    bool isValidBST(TreeNode* root) {
        // inorder traversal
        stack<TreeNode*> s;
        TreeNode *current = root;
        TreeNode *prev = nullptr; // record the right most node on the left
        
        // Note: current is the current root of this inorder traversal subtree
        // End when current pointer is nullptr and stack is empty
        while(current != nullptr or !s.empty()){
            // travese to the end on the left
            while(current != nullptr){
                s.push(current); // save the current path
                current = current->left;
            }
            current = s.top();
            s.pop();
            // if one pair of nodes violate the rule, we are finished
            if(prev != nullptr and prev->val >= current->val){
                return false;
            }           
            prev = current;
            // if current->right == nullptr, we will skip it(see above while loop)
            current = current->right;
        }
        return true;
    }
};
