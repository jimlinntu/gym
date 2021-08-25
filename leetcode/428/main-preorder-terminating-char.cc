/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    void encode(Node *root, string &s){
        if(root){
            s += to_string(root->val) + ",";
            for(Node *c: root->children){
                encode(c, s);
            }
        }else{
            // Note: this is necessary
            // Consider this case vector<Node*> = [Node, nullptr, Node]
            s += "N,";
        }
        s += "#"; // ending character
    }
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        encode(root, s);
        return s;
    }
	Node* decode(string &s, int &cur){
        if(s[cur] == 'N'){
            // consume "N,#"
            assert(s[cur+1] == ',' and s[cur+2] == '#');
            cur += 3;
            return nullptr;
        }
        int idx = s.find(',', cur);
        int val = stoi(s.substr(cur, idx-cur));
        Node *root = new Node(val);
        cur = idx+1;

        // while this substree hasn't ended
        while(s[cur] != '#'){
            root->children.push_back(decode(s, cur));
        }
        assert(s[cur] == '#');
        cur++;
        return root;
    }
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int cur = 0;
        return decode(data, cur);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
