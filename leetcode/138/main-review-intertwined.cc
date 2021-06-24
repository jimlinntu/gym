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
        // Intertwine two list together
        for(Node *cur = head; cur != nullptr; cur = cur->next->next){
            // Copy a node behind it
            Node *new_node = new Node(cur->val);
            new_node->next = cur->next;
            cur->next = new_node;
        }
        // Modify new_node->random to the new node
        for(Node *cur = head; cur != nullptr; cur = cur->next->next){
            Node *new_cur = cur->next;
            // Point the new node
            if(cur->random != nullptr) new_cur->random = cur->random->next;
            else new_cur->random = nullptr;
        }
        // Decompose two list
        Node dummy(0);
        Node *prev = &dummy;
        for(Node *cur = head; cur != nullptr; cur = cur->next){
            // Remove the new node from the intertwined list
            prev->next = cur->next;
            prev = cur->next;

            cur->next = cur->next->next;
        }
        return dummy.next;
    }
};
