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
    int n;
    unordered_map<int, int> map;
    TreeNode* build(vector<int> &preorder, vector<int> &inorder,
                    int &pre_start, int in_start, int in_end){
        if(pre_start >= n) return nullptr;
        if(in_start >= in_end) return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_start]);
        int mid = map[preorder[pre_start]];
        pre_start++;
        // [in_start, mid)
        root->left = build(preorder, inorder, pre_start, in_start, mid);
        // [mid+1, in_end)
        root->right = build(preorder, inorder, pre_start, mid+1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = inorder.size();
        for(int i = 0; i < n; i++){
            map[inorder[i]] = i;
        }
        int pre_start = 0;
        return build(preorder, inorder, pre_start, 0, n);
    }
};
