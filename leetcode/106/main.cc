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
    unordered_map<int, int> in_val2idx;

    TreeNode* _build(int in_left, int in_right,
                     int post_left, int post_right,
                     vector<int> &inorder,
                     vector<int> &postorder){
        // [left, right)

        // base case
        if(post_right - post_left == 1){
            return new TreeNode(postorder[post_left]);
        }
        // the value of the current TreeNode
        int val = postorder[post_right-1];
        int in_idx = in_val2idx[val];
        int left_size = in_idx - in_left, right_size = in_right - in_idx - 1;

        TreeNode *left_child = nullptr;
        TreeNode *right_child = nullptr;

        if(left_size != 0){
            left_child = _build(in_left, in_idx,
                                post_left, post_left+left_size,
                                inorder, postorder);
        }
        
        if(right_size != 0){
            right_child = _build(in_idx+1, in_right,
                                 post_right-1-right_size, post_right-1,
                                 inorder, postorder);
        }

        return new TreeNode(val, left_child, right_child);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return nullptr;
        for(int i = 0; i < n; i++){
             in_val2idx[inorder[i]] = i;
        }
        TreeNode *root = _build(0, n, 0, n, inorder, postorder);
        return root;
    }
};
