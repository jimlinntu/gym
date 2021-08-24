/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // BFS
        string s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *cur = q.front();
            q.pop();
            if(cur){
                q.push(cur->left);
                q.push(cur->right);
                s += to_string(cur->val) + ",";
            }else{
                s += "N,";
            }
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> split;
        int cur = 0;
        while(true){
            string::size_type idx = data.find(',', cur);
            if(idx == string::npos) break;
            split.push_back(data.substr(cur, idx-cur));
            cur = idx+1;
        }
        assert(split.size() >= 1);
        TreeNode *root = nullptr;
        if(split[0] != "N") root = new TreeNode(stoi(split[0]));
        queue<TreeNode*> q;
        if(root) q.push(root);

        // Tricky:
        // This is bascially a level order traversal
        // you can imagine `i` point to the next level's
        // while queue represents the parents
        // When the parents finish, i will immediately point to the next level!
        for(int i = 1; i < split.size(); i++){
            assert(!q.empty());
            TreeNode *parent = q.front();
            q.pop();

            if(split[i] != "N"){
                parent->left = new TreeNode(stoi(split[i]));
                q.push(parent->left);
            }
            i++; // consume one
            if(split[i] != "N"){
                parent->right = new TreeNode(stoi(split[i]));
                q.push(parent->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
