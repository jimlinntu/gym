/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node *prev = &dummy;
        unordered_map<Node*, Node*> m;
        for(Node *cur = head; cur != nullptr; cur = cur->next){
            prev->next = new Node(cur->val); // append
            m[cur] = prev->next;

            prev = prev->next; // move on
        }
        for(Node *cur=head, *new_cur=dummy.next; cur != nullptr;
                cur = cur->next, new_cur = new_cur->next){
            new_cur->random = m[cur->random];
        }
        return dummy.next;
    }
};
