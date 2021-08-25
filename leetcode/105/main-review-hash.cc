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
    unordered_map<int, int> map;
    TreeNode* solve(vector<int> &preorder, int pstart, int pend,
                    vector<int> &inorder, int istart, int iend){
        if(pstart >= pend) return nullptr;
        
        int val = preorder[pstart];
        int iidx = map[val];

        int left_len = iidx - istart;
        int right_len = iend - (iidx+1);
        TreeNode *root = new TreeNode(val);
        root->left = solve(preorder, pstart+1, pstart+1+left_len,
                               inorder, istart, iidx);
        root->right = solve(preorder, pstart+1+left_len, pend,
                               inorder, iidx+1, iend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Observation:
        // preorder must be like
        // tree -> [root, <left tree>, <right tree>]
        // inorder must be like
        // tree -> [<left tree>, root, <right tree>]
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        int n = preorder.size();
        return solve(preorder, 0, n, inorder, 0, n);
    }
};
