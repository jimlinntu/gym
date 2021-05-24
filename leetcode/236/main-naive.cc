/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // O(n) space
    unordered_set<TreeNode*> path;
    TreeNode *ans = nullptr;
    // O(n) time
    bool find_p(TreeNode *root, TreeNode *p){
        if(root == nullptr) return false;
        path.insert(root);
        if(root == p) return true;
        
        if(find_p(root->left, p) or find_p(root->right, p)) return true;
        path.erase(root);
        return false;
    }
    // O(n) time
    bool find_q(TreeNode *root, TreeNode *q){
        if(root == nullptr) return false;
        if(root == q){
            if(ans == nullptr and path.find(root) != path.end())
                ans = root;
            return true;
        }
        if(find_q(root->left, q) or find_q(root->right, q)){
            // Check if this root is on the path of path2p
            if(ans == nullptr and path.find(root) != path.end())
                ans = root;
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert(find_p(root, p));
        assert(find_q(root, q));
        return ans;
    }
};
