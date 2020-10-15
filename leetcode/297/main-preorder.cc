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
    
    void _traverse(TreeNode *cur, string &data){
        // the start of this substree
        data += to_string(cur->val) + " ";
        if(cur->left != nullptr){
            _traverse(cur->left, data);
        }
        data += "# "; // mark the left branch has ended
        if(cur->right != nullptr){
            _traverse(cur->right, data);
        }
        data += "# "; // mark the right branch (also this subtree has ended)
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        if(root == nullptr) return data;
        _traverse(root, data);
        return data;
    }

    void _parse(string &data, vector<string> &symbols){
        size_t start = 0;
        while(true){
            size_t last = data.find(" ", start);
            if(last == string::npos) break;
            symbols.push_back(data.substr(start, last-start));
            start = last+1; // the length of a whitespace is 1
        }
        return;
    }

    void _reconstruct(TreeNode *cur, int &idx, vector<string> &symbols){
        string sym = symbols[idx++];
        if(sym != "#"){
            cur->left = new TreeNode(stoi(sym));
            _reconstruct(cur->left, idx, symbols);
            // consume the end of the left branch #
            sym = symbols[idx++];
            assert(sym == "#");
        }

        sym = symbols[idx++];
        if(sym != "#"){
            cur->right = new TreeNode(stoi(sym));
            _reconstruct(cur->right, idx, symbols);
            // consume the end of the right branch #
            sym = symbols[idx++];
            assert(sym == "#");    
        }
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> symbols;
        _parse(data, symbols);
        if(symbols.size() == 0) return nullptr;
        TreeNode *root = new TreeNode(stoi(symbols[0]));
        int idx = 1;
        _reconstruct(root, idx, symbols);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
