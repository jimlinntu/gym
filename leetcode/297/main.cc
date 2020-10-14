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
        queue<TreeNode*> q;
        TreeNode *cur;
        bool all_null = false;
        q.push(root);
        string data;
        while(!q.empty() and !all_null){
            all_null = true; // assume the next level has no nodes
            for(int i = q.size(); i > 0; i--){
                cur = q.front();
                q.pop();
                if(cur == nullptr){
                    data += "n ";
                    continue;
                }else{
                    data += to_string(cur->val) + " ";
                }
                if(cur->left != nullptr or cur->right != nullptr){
                    all_null = false;
                }
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return data;
    }
    void parse_data(string &data, vector<string> &nodes){
        size_t start = 0;
        size_t pos;
        while(true){
            pos = data.find(" ", start);
            if(pos == string::npos) break;
            nodes.push_back(data.substr(start, pos-start));
            start = pos+1;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        parse_data(data, nodes);
        int n = nodes.size();
        // n == 0 will never happen!
        // because if root == nullptr, data == "n "
        if(n == 0) return nullptr;
        TreeNode *root;
        if(nodes[0] == "n") root = nullptr;
        else root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int start = 1;
        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                TreeNode *cur = q.front();
                q.pop();
                if(cur == nullptr) continue;
                TreeNode *left = nullptr;
                TreeNode *right = nullptr;
                // left
                if(start < nodes.size() and nodes[start] != "n"){
                    left = new TreeNode(stoi(nodes[start]));
                }
                start++;
                // right
                if(start < nodes.size() and nodes[start] != "n"){
                    right = new TreeNode(stoi(nodes[start]));
                }
                start++;
                if(left != nullptr) q.push(left);
                if(right != nullptr) q.push(right);
                cur->left = left;
                cur->right = right;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
