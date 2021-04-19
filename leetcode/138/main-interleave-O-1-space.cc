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
        if(head == nullptr) return nullptr;
        // Idea: interleave the original list and copied list
        Node *next;
        for(Node *cur = head; cur != nullptr; cur = next){
            //     1 --> 2 --> 3
            // ==> 1 --> 1* --> 2 --> 3
            //          ^^^ <----------- copied node
            Node *new_node = new Node(cur->val);
            next = cur->next;
            new_node->next = next;
            new_node->random = cur->random;
            cur->next = new_node;
        }
        for(Node *cur = head; cur != nullptr; cur = next){
            next = cur->next->next;
            Node *copied = cur->next;
            if(copied->random != nullptr)
                copied->random = copied->random->next;
        }
        Node *new_head = head->next;
        // Remove copied nodes inside it and extract copied nodes
        for(Node *cur = head; cur != nullptr; cur = next){
            Node *copied = cur->next;
            assert(copied != nullptr);
            next = copied->next;
            if(next != nullptr)
                copied->next = next->next;
            cur->next = next;
        }
        
        return new_head;
    }
};
