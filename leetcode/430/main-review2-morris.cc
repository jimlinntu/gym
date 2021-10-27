/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* cur = head; cur != nullptr; cur = cur->next){
            if(cur->child == nullptr) continue;
            Node *tail = cur->child;
            while(tail->next != nullptr)
                tail = tail->next;
            // tail <---> cur->next
            tail->next = cur->next;
            if(cur->next)
                cur->next->prev = tail;
            
            // cur  <---> cur->child
            cur->next = cur->child;
            cur->child->prev = cur;
            
            cur->child = nullptr;
        }
        return head;
    }
};
