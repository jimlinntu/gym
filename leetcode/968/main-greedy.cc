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
    int ans = 0;
    // if this node has a parent, delay it for its parent to add
    pair<bool, bool> solve(TreeNode *root, bool hasparent){
        // {is covered, has camera}
        if(root == nullptr) return {true, false};

        auto [l_cover, l_camera] = solve(root->left, true);
        auto [r_cover, r_camera] = solve(root->right, true);

        // if one of its children has not been covered
        // we must place here
        if(!(l_cover and r_cover)){
            ans++;
            return {true, true};
        }
        // if one of its children has camera
        // do not need put a camera here
        if(l_camera or r_camera) return {true, false};
        
        // rely on its parent to save him
        if(hasparent) return {false, false};
        // must put a camera here
        ans++;
        return {true, true};
    }
    int minCameraCover(TreeNode* root) {
        assert(solve(root, false).first);
        return ans;
    }
};
